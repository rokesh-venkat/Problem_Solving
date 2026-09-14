#include <bits/stdc++.h>
using namespace std;
void solve() {
    int N,M;
    cin >> N >> M;
    vector<int> cnt(M+1,0);
    for(int ctr=1;ctr <= N;ctr++){
        int curr;
        cin >> curr;
        cnt[curr]++;
    }

vector<int> psum(M+1,0);

for(int i=1;i <= M;i++){
    psum[i]=psum[i-1]+cnt[i];
}
int ans=0;
for(int x=1;x <= M;x++){
    int currcnt=psum[M]-psum[x-1];
    if(2*x <= M){
        currcnt+=cnt[2*x];
    }
ans=max(ans,currcnt);
}
cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
return 0;
}
