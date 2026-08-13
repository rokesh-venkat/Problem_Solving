#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int find(vector<int>& ldr, int node) {
    if (ldr[node] != node) {
        ldr[node] = find(ldr, ldr[node]);
    }
    return ldr[node];
}

void join(vector<int>& ldr, int rtld, int lfld) {
    ldr[find(ldr, rtld)] = find(ldr, lfld);
}
void solve(){
  int N,E; cin>>N>>E;
  vector<int> ldr(N+1);
  for(int node=1;node <=N;node++){
    ldr[node]=node;
  }
  vector<pair<int,int>> edge(E);
  for(int i=0;i<E;i++){
    int a,b; cin>>a>>b;
    edge[i]=make_pair(a,b);
    join(ldr,a,b);
  }
  
  vector<int> gcnt(N+1,0),ecnt(N+1,0);
  for(int node=1;node<=N;node++){
    gcnt[find(ldr,node)]++;
  }
  for(auto [a,b]:edge){
    ecnt[find(ldr,a)]++;
  }
  
  ll ans=0;
  for(int node=1;node<=N;node++){
    if (ldr[node] == node) {
            ll curr = (1ll * gcnt[node] * (gcnt[node] - 1) / 2) - ecnt[node];
            ans += curr;
        }
  }
  cout << ans;
  
}
int main(){
  ios_base:: sync_with_stdio(false);
  cin.tie(0);
  //cin>>t;
  int t=1;
  while(t--){
    solve();
  }
  return 0;
}
