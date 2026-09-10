#include <bits/stdc++.h>
#define ll long long 
using namespace std;

void solve(){
	int N;
	cin>>N;
	vector<int> arr(N);
	int count=0;
	for(int i=0;i<N;i++){
		cin>>arr[i];
		count+=arr[i];
	}
	int zc=N-count;
	if(zc<2){
		cout<<"-1\n";
		return;
	}
	int ans=0;
	if(arr[0]) ans++;
	if(arr[N-1]) ans++;
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