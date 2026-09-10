#include <bits/stdc++.h>
#define ll long long 
using namespace std;

void solve(){
	ll x,y,k;
	cin>>x>>y>>k;
	ll ans=0;
	ll ctr=0;
	while(ctr<k){
		ll rem= (y+ctr)%(x+ctr);
		if(rem==y-x){
			break;
		}
		ans+=rem;
		ctr++;
	}
	
	if(k>ctr){
		ans+=(k-ctr)*(y-x);
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