#include <bits/stdc++.h>
using namespace std;
void solve(){
	int N;
	cin>>N;
	set<int> comp;
	while(N--){
		int i;
		cin>>i;
		comp.insert(i);
	}
	
	cout<<comp.size()<<endl;
	for(int val : comp){
		cout<<val<<" ";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--){
		solve();
	}
	return 0;
}