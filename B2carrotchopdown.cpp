#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve(){
    int N, M; cin >> N >> M;
    vector<int> cnt(M + 1, 0);
    for (int ctr = 1; ctr <= N; ctr++) {
        int curr; cin >> curr;
        if (curr <= M) {
            cnt[curr]++;
        }
}
vector<int> psum(M + 1, 0);
for (int cl = 1; cl <= M; cl++) {
    psum[cl] = psum[cl - 1] + cnt[cl];
}
vector<ll> ans(max(M, 18) + 1, 0);
for (int cut = 1; cut <= 18; cut++) {
    ll maxc = 0;
    for (int x = 1; x <= M; x++) {
        ll currc = 0;
        for (int mul = 1; mul * x <= M; mul++) {
            int lt = mul * x;
            int rt = lt + x - 1;
            currc += min(1ll * mul, (1ll << cut) - 1) * (psum[min(rt, M)] - psum[lt - 1]);
        }
    if (cut <= 30 && (1ll << cut) <= M / x) {
        int idx = (1ll << cut) * x;
        if (idx <= M) {
            currc += cnt[idx];
        }
}
maxc = max(maxc, currc);
}
ans[cut] = maxc;
}
 
for (int cut = 1; cut <= M; cut++) {
    cout << ans[min(cut, 18)] << (cut == M ? "\n" : " ");
}
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
