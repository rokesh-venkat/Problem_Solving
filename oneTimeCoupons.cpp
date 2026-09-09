#include <bits/stdc++.h>
#define ll long long 
using namespace std;

void solve(){
  int N; cin>>N;
  vector<pair<int,int>> arr(N);
  int mini = 2e9;
  ll base=0;
  for(int i=0;i<N;i++){
    cin>> arr[i].first >> arr[i].second;
    mini = min(mini,arr[i].first);
    base+=arr[i].first;
  }
  
  sort(arr.begin(),arr.end(),[] (const pair<int,int>& a,const pair<int,int>& b){
   return a.first-a.second>b.first-b.second; 
  });
  
  ll ans= base;
  for(int i=1;i<=N;i++){
    base-=arr[i-1].first;
    base+=arr[i-1].second;
    ll curr= base+((N-i)>=i?0:1ll*mini*(i-(N-i)));
    ans=min(ans,curr);
  }
  cout<<ans<<endl;
}
int main(){
  ios_base:: sync_with_stdio(false);
  cin.tie(0);
 
  int t;
  cin>>t;
  while(t--){
    solve();
  }
  return 0;
}