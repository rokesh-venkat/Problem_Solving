#include <bits/stdc++.h>
#define ll long long 
using namespace std;

void solve(){
  int R,C,K;
  cin>>R>>C>>K;
  vector<string> g(R);
  for(int row=0;row<R;row++) cin>>g[row];
  queue<pair<int,int>> q;
  vector<bool> br(R,false),bc(C,false);
  for(int row=0;row<R;row++){
    for(int col=0;col<C;col++){
      if(g[row][col]=='#'){
        br[row]=bc[col]=true;
      }
    }
  }
  vector<vector<bool>> vis(R,vector<bool>(C,false));
  for(int row =0;row<R;row++){
    for(int col=0;col<C;col++){
      if(!br[row] && !bc[col]){
        q.push(make_pair(row,col));
        vis[row][col]=true;
      }
    }
  }
  vector<vector<int>> diff = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  ll cellcnt = 0;
  int holes=0;
  while(!q.empty() && holes<=K){
    
    int qsize= q.size();
    cellcnt +=qsize;
    if (holes == K) break;
    while(qsize--){
      auto[row,col]=q.front();
      q.pop();
      for(int i =0;i<4;i++){
        int ar= row + diff[i][0];
        int ac= col+diff[i][1];
        if (ar >= 0 && ar < R && ac >= 0 && ac < C) {
          if (!vis[ar][ac] && g[ar][ac] != '#') {
             vis[ar][ac] = true;
             q.push({ar, ac});
            }
        }
      }
    }
    holes++;
  }
  cout<<cellcnt<<endl;
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