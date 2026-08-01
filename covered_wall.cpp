#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N,M;
  cin>>N>>M;
  vector<int> result(N+2,0);
  for(int i=0;i<M;i++){
    int L,R;
    cin>>L>>R;
    result[L]+=1;
    result[R+1]-=1;
  }
  
  int current_turret=0;
  int min_turret = M+1;
  for(int i=1;i<=N;i++){
    current_turret+=result[i];
    min_turret = min(min_turret,current_turret);
  }
  
  cout<<min_turret;
  
  return 0;
  
  
}