#include <bits/stdc++.h>
#define ll long long 
using namespace std;
void getInput(vector<int>& arr,int N){
	for(int i=0;i<N;i++) cin>>arr[i];
	sort(arr.begin(),arr.end());
}
 
void solve(){
	int N;
	cin>>N;
	vector<int> up(N),mid(N),low(N);
	getInput(up,N);
	getInput(mid,N);
	getInput(low,N);
	vector<ll> prefixmid(N,0);
	for(int i=0;i<N;i++){
		auto it=upper_bound(low.begin(),low.end(),mid[i]);
		if(it!=low.end()){
			prefixmid[i]=low.end()-it;
		}
	}
	for(int i=1;i<N;i++){
		prefixmid[i]+=prefixmid[i-1];
	}
	ll ans=0;
	for(int i=0;i<N;i++){
		auto it = upper_bound(mid.begin(),mid.end(),up[i]);
		if(it!=mid.end()){
			int midx =it - mid.begin();
			ans+=prefixmid[N-1]-(midx==0?0:prefixmid[midx-1]);
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