#include <bits/stdc++.h>
#define ll long long 
using namespace std;


 
void solve(){
	int N;
	cin>>N;
	vector<int> a(N);
	for(int i=0;i<N;i++){
	  cin>>a[i];
	}
	// cause the overflow for the larger values 
    //int lcm_a = accumulate(a.begin(),a.end(),1,lcm<int,int>);
    //int m= lcm_a -1;
	int sum =0;
	for(int i=0;i<N;i++){
	  //sum+= (m%a[i]);
	  sum+= (a[i]-1);
	}
	
	cout<<sum<<endl;
    
	
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