#include <bits/stdc++.h>
#define ll long long 
using namespace std; 
struct Bus_seg{
	ll lt,rt;
	double time;
	friend bool operator< ( Bus_seg a,Bus_seg b){
		if(a.lt!=b.lt){
			return a.lt<b.lt;
		}
		return a.time<b.time;
	}
}buses[200000];

void solve(){
	ll B,P,L,bspeed,pspeed,pos;
	cin>>B>>P>>L>>bspeed>>pspeed;
	for(int i=0;i<B;i++){
		cin>>buses[i].lt>>buses[i].rt;
		buses[i].time= (double)(buses[i].rt - buses[i].lt)/(double) bspeed+(double)(L-buses[i].rt)/pspeed;
		
	}
	
	sort(buses,buses+B);
	
	for(int i=0;i<B-1;i++){
		buses[i+1].time=min(buses[i+1].time,buses[i].time);
	}
	double ans;
	for(int ctr=1;ctr<=P;ctr++){
		cin>>pos;
		ans=(double)(L-pos)/pspeed;
		int bus_left=0,bus_right=B;
		bool found=false;
		while(bus_left<bus_right){
			int mid= (bus_left+bus_right)/2;
			if(buses[mid].lt<=pos){
				found=true;
				if(bus_left==mid) break;
				bus_left=mid;
			}else{
				bus_right=mid;
			}
		}
		if(found){
			ans=min(ans,buses[bus_left].time);
		}
		
		cout<<setprecision(11)<<ans<<endl;
	}
	
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