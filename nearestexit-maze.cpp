#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    const int d[5] = {0, 1, 0, -1, 0};
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        int R = maze.size();
        int C = maze[0].size();
        queue<tuple<int, int, int>> q;
        
        q.push(make_tuple(e[0], e[1], 0));
        maze[e[0]][e[1]] = '+';
        
        while (!q.empty()) {
            auto [row, col, steps] = q.front();
            q.pop();
            
            if (row == 0 || row == R - 1 || col == 0 || col == C - 1) {
                if (row != e[0] || col != e[1]) {
                    return steps;
                }
            }
            
            for (int i = 0; i < 4; i++) {
                int ar = row + d[i];
                int ac = col + d[i + 1];
                
                if (ar >= 0 && ar < R && ac >= 0 && ac < C && maze[ar][ac] == '.') {
                    maze[ar][ac] = '+';
                    q.push(make_tuple(ar, ac, steps + 1));
                }
            }
        }
        return -1;
    }
};

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    int m, n;
    if (!(cin >> m >> n)) return 0;
    
    vector<vector<char>> maze(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }
    
    vector<int> entrance(2);
    cin >> entrance[0] >> entrance[1];
    
    Solution solution;
    int ans = solution.nearestExit(maze, entrance);
    
    cout << ans << endl;
    
    return 0;
}