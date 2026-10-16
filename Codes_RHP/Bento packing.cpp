#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
	int N,W;
	cin>>N>>W;
	vector<int> deli(N),vol(N);
	for(int i=0;i<N;i++){
		cin>>deli[i]>>vol[i];
	}
	ll maxdeli= 0;
	for(int ctr =1;ctr<(1<<N);ctr++){
		ll currdeli =0,currvol=0;
		for(int sh=0; sh<N;sh++){
			if((ctr & (1<<sh))!=0){
				currdeli +=deli[sh];
				currvol+=vol[sh];
			}
		}
		if(currvol<=W && currdeli > maxdeli){
			maxdeli = currdeli;
		}
	}
	cout<<maxdeli<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}