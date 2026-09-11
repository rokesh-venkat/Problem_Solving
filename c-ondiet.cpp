#include <bits/stdc++.h>
#define ll long long 
using namespace std;

void solve(){
 int N, M;
    ll K;
    if (!(cin >> N >> M >> K)) return;

    vector<ll> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    vector<bool> eaten(N, false);
    ll curr = 0;

    for (int i = 0; i < N; i++) {
        // Subtract the calorie value of the snack eaten M days ago
        if (i >= M && eaten[i - M]) {
            curr -= arr[i - M];
        }

        // Check if Takahashi can eat the snack on day i
        if (curr + arr[i] <= K) {
            cout << "Yes\n";
            eaten[i] = true;
            curr += arr[i];
        } else {
            cout << "No\n";
        }
    }
}
int main(){
  ios_base:: sync_with_stdio(false);
  cin.tie(0);
  //cin>>t;
  int t=1;
  while(t--){
    solve();
  }
  return 0;
}