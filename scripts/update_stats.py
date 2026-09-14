#!/usr/bin/env python3
"""
Fetch coding platform stats and update README.md
Supports: LeetCode, Codeforces, AtCoder, HackerRank
"""

import requests
import re
import json
from datetime import datetime

# Configuration
LEETCODE_USERNAME = "rokesh_lc"
CODEFORCES_USERNAME = "Rokesh_Venkat"
ATCODER_USERNAME = "Rokesh_Venkat"
HACKERRANK_USERNAME = "RokeshVenkat"

# API Endpoints
LEETCODE_API = "https://leetcode-stats-api.herokuapp.com/api"
CODEFORCES_API = "https://codeforces.com/api/user.info"
ATCODER_API = "https://atcoder.jp/users/{}/history/json"

class StatsCollector:
    def __init__(self):
        self.stats = {}
        self.last_updated = datetime.now().strftime("%Y-%m-%d %H:%M UTC")

    def fetch_leetcode_stats(self):
        """Fetch LeetCode stats"""
        try:
            params = {"username": LEETCODE_USERNAME, "theme": "dark"}
            response = requests.get(LEETCODE_API, params=params, timeout=10)
            
            if response.status_code == 200:
                data = response.json()
                self.stats['leetcode'] = {
                    'total_solved': data.get('totalSolved', 0),
                    'total_questions': data.get('totalQuestions', 0),
                    'easy_solved': data.get('easySolved', 0),
                    'medium_solved': data.get('mediumSolved', 0),
                    'hard_solved': data.get('hardSolved', 0),
                    'acceptance_rate': data.get('acceptanceRate', 0),
                    'ranking': data.get('ranking', 'N/A'),
                }
                print("✅ LeetCode stats fetched successfully")
                return True
        except Exception as e:
            print(f"❌ Error fetching LeetCode stats: {e}")
        return False

    def fetch_codeforces_stats(self):
        """Fetch Codeforces stats"""
        try:
            params = {"handles": CODEFORCES_USERNAME}
            response = requests.get(CODEFORCES_API, params=params, timeout=10)
            
            if response.status_code == 200:
                data = response.json()
                if data['status'] == 'OK' and data['result']:
                    user = data['result'][0]
                    self.stats['codeforces'] = {
                        'rating': user.get('rating', 'Unrated'),
                        'max_rating': user.get('maxRating', 'N/A'),
                        'contribution': user.get('contribution', 0),
                        'friend_count': user.get('friendOfCount', 0),
                        'last_online': user.get('lastOnlineTimeSeconds', 0),
                    }
                    print("✅ Codeforces stats fetched successfully")
                    return True
        except Exception as e:
            print(f"❌ Error fetching Codeforces stats: {e}")
        return False

    def fetch_atcoder_stats(self):
        """Fetch AtCoder stats"""
        try:
            url = ATCODER_API.format(ATCODER_USERNAME)
            response = requests.get(url, timeout=10)
            
            if response.status_code == 200:
                data = response.json()
                if data:
                    latest = data[-1] if isinstance(data, list) else data
                    self.stats['atcoder'] = {
                        'highest_rating': latest.get('HighestRating', 0),
                        'rating': latest.get('Rating', 0),
                        'contests': len(data) if isinstance(data, list) else 1,
                    }
                    print("✅ AtCoder stats fetched successfully")
                    return True
        except Exception as e:
            print(f"❌ Error fetching AtCoder stats: {e}")
        return False

    def generate_stats_table(self):
        """Generate markdown table with current stats"""
        markdown = "\n## 📊 Live Platform Stats\n\n"
        markdown += f"*Last Updated: {self.last_updated}*\n\n"
        
        # LeetCode
        if 'leetcode' in self.stats:
            lc = self.stats['leetcode']
            total = lc['total_solved']
            markdown += f"### 🟡 LeetCode\n\n"
            markdown += f"![LeetCode](https://img.shields.io/badge/Solved-{total}%2F{lc['total_questions']}-FFA116?style=flat-square)\n"
            markdown += f"![Acceptance](https://img.shields.io/badge/Acceptance-{lc['acceptance_rate']:.1f}%25-green?style=flat-square)\n\n"
            markdown += f"| Easy | Medium | Hard |\n"
            markdown += f"|------|--------|------|\n"
            markdown += f"| {lc['easy_solved']} | {lc['medium_solved']} | {lc['hard_solved']} |\n\n"
        
        # Codeforces
        if 'codeforces' in self.stats:
            cf = self.stats['codeforces']
            rating = cf['rating']
            markdown += f"### 🔵 Codeforces\n\n"
            markdown += f"![Rating](https://img.shields.io/badge/Rating-{rating}-1F8ACB?style=flat-square)\n"
            markdown += f"![Max Rating](https://img.shields.io/badge/Max-{cf['max_rating']}-blue?style=flat-square)\n\n"
        
        # AtCoder
        if 'atcoder' in self.stats:
            ac = self.stats['atcoder']
            markdown += f"### ⚪ AtCoder\n\n"
            markdown += f"![Rating](https://img.shields.io/badge/Rating-{ac['rating']}-orange?style=flat-square)\n"
            markdown += f"![Contests](https://img.shields.io/badge/Contests-{ac['contests']}-lightgrey?style=flat-square)\n\n"
        
        return markdown

    def update_readme(self):
        """Update README.md with fetched stats"""
        try:
            with open('README.md', 'r', encoding='utf-8') as f:
                content = f.read()
            
            # Find or create stats section
            stats_section = self.generate_stats_table()
            
            # Replace or insert stats section
            # Look for existing "## 📊 Live Platform Stats" section
            pattern = r'## 📊 Live Platform Stats\n\n.*?(?=\n## [^#]|\Z)'
            
            if re.search(pattern, content, re.DOTALL):
                # Replace existing section
                content = re.sub(
                    pattern,
                    stats_section.strip() + '\n',
                    content,
                    flags=re.DOTALL
                )
                print("✅ Updated existing stats section in README.md")
            else:
                # Insert after "## 📊 Platform Stats" or at the beginning
                insert_pos = content.find('\n---')
                if insert_pos != -1:
                    content = content[:insert_pos] + '\n' + stats_section + content[insert_pos:]
                    print("✅ Inserted new stats section in README.md")
            
            # Write back
            with open('README.md', 'w', encoding='utf-8') as f:
                f.write(content)
            
            return True
        except Exception as e:
            print(f"❌ Error updating README.md: {e}")
            return False

    def run(self):
        """Run all stat collection and update"""
        print("🚀 Starting stats update...\n")
        
        self.fetch_leetcode_stats()
        self.fetch_codeforces_stats()
        self.fetch_atcoder_stats()
        
        if self.update_readme():
            print("\n✅ Stats updated successfully!")
        else:
            print("\n❌ Failed to update stats")

if __name__ == "__main__":
    collector = StatsCollector()
    collector.run()