#include <bits/stdc++.h>
#define ll long long 
using namespace std;
 
void solve(){
	int x,y;
	cin>>x>>y;
	int max_xy = x+y;
	int rx=0,ry=0;
	for(int sf=30;sf>=0;sf--){
		if((max_xy&(1<<sf))!=0 ){
			if((rx|(1<<sf))<=x){
				rx=rx|(1<<sf);
			}else{
				ry=ry|(1<<sf);
			}
		}
	}
	
	cout<<max_xy<<" "<<(x-rx)<<endl;
  
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