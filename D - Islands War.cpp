#include <bits/stdc++.h>
#define ll long long 
using namespace std; 
void solve(){
	int N,Q;
	cin>>N>>Q;
	vector<pair<int,int>> arr(Q);
	for(int i=0;i<Q;i++){
		int lt,rt;
		cin>>lt>>rt;
		arr[i] = {rt,lt};
		
	}
	sort(arr.begin(),arr.end());
	int count =0,rtmax=-1;
	for(auto[rt,lt]:arr){
		if(lt>=rtmax){
			count++;
			rtmax=rt;
		}
	}
    cout<<count<<endl;
	
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