#include <bits/stdc++.h>
using namespace std;
void solve() {
    int N; cin >> N;
    vector<int> arr(N);
    vector<int> zeroidx;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (arr[i] == 0) zeroidx.push_back(i);
    }
if (zeroidx.size() == 1) {
    cout << "NO" << endl; 
    return;
}
string s(N, 'C');
if (zeroidx.size() > 0) {
    int fzidx = zeroidx[0];
    s[fzidx] = 'B';
    for (unsigned int i = 1; i < zeroidx.size(); i++) {
        s[zeroidx[i]] = 'A';
    }
}
cout << "YES" << endl << s << endl;
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
