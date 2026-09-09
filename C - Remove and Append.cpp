#include <bits/stdc++.h>
#include <vector>

using namespace std;

void solve() {
	int N,Q;
	cin>>N>>Q;
	vector<int> pos(N+1);
	for(int p=1;p<=N;p++){
	  int curr;
	  cin>>curr;
	  pos[curr]=p;
	  
	}
	int nextpos=N+1;
	while(Q--){
	  int val;
	  cin>>val;
	  pos[val]=nextpos++;
	  }
	  vector<pair<int,int>> arr;
	  for(int val=1;val<=N;val++){
	    arr.push_back({pos[val],val});
	  }
	  sort(arr.begin(),arr.end());
	  for(auto [p,v]: arr){
	    cout<<v<<" ";
	  }
	  
	  cout<<endl;
	  
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
        
    
    return 0;
}