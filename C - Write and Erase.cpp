#include <bits/stdc++.h>
#define ll long long 
using namespace std;

 
void solve(){
	int N;
	cin>>N;
  unordered_map<int,int> count;
  for(int i=0;i<N;i++){
    int val;
    cin>>val;
    count[val]++;
  }
  int ans=0;
  for(auto [val,cnt]:count){
    if(cnt%2!=0){
        ans++;
    }
  }
  cout<<ans<<endl;
	
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