#include <bits/stdc++.h>
#define ll long long 
using namespace std;
 
void solve(){
	int N;
	cin>>N;
	vector<int> common(26,50);
	for(int ctr=1;ctr<=N;ctr++){
		string s;
		cin>>s;
		vector<int> curr(26,0);
		for(char ch:s){
			curr[(ch-'a')]++;
			
		}
		for(int i=0;i<26;i++){
			common[i] =min(common[i],curr[i]);
		}
	}
	for(int i=0;i<26;i++){
		while(common[i]--){
		cout<<(char) ('a'+i);
		}
	}
	
	
  
}
int main(){
  ios_base:: sync_with_stdio(false);
  cin.tie(0);
 
  int t=1;
  //cin>>t;
  while(t--){
    solve();
  }
  return 0;
}