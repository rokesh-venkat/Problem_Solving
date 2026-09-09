#include <bits/stdc++.h>
#include <vector>

using namespace std;

void solve() {
	int N; 
	cin>>N;
	int st=1,end=10;
	for(int ctr=1;ctr<=N;ctr++){
		int curr; cin>>curr;
		if(!(curr>=st && curr<=end)){
			cout<<"No"<<endl;
			return;
		}
	
		if(ctr%10==0){
		  st+=10;
		  end+=10;
		}
	}
	
	cout<<"Yes"<<endl;
   
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
        
    
    return 0;
}