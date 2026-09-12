#include <bits/stdc++.h>
#define ll long long 
using namespace std;

 
void solve(){
	string s,t;
	cin>>s>>t;
	
	string tt = t+t;
	cout<<(tt.contains(s)?"Yes":"No")<<endl;
    
	
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