#include <bits/stdc++.h>
#define ll long long 
using namespace std;
 
void solve(){
	int N;
	string s;
	cin>>N>>s;
	if(s[0]=='0'||s.contains("00")){
		cout<<"-1"<<endl;
		return;
	}
	int ans=-1;
	if(s.contains("+-")||s.contains("-+")){
		if(s.contains("+--+")||s.contains("-++-")){
			ans=3;
		}else{
			ans=2;
		}
	}else{
		ans=1;
		for(int i=0;i<N;i+=2){
			if(s[i]=='0'){
				ans=2;
				break;
			}
		}
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