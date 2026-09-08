#include <bits/stdc++.h>
using namespace std;

void solve(){
    int N; cin>>N;
    vector<int> arr(N+1), psum(N+1,0);
    string ans="";
    for(int i=1;i<=N;i++){
        cin>>arr[i];
        if(arr[i]>0){
            psum[max(1,i-arr[i]+1)]++;
            if(i+arr[i]<=N){
                psum[i+arr[i]]--;
            }
        }
    }
    for(int i=1;i<=N;i++){
        psum[i]+=psum[i-1];
    }
    for(int i=1;i<=N;i++){
        if(arr[i]!=-1){
            bool valid = false;
            if(i-arr[i]>=1 && psum[i-arr[i]]==0) valid= true;
            if(i+arr[i]<=N && psum[i+arr[i]]==0) valid=true;
            if(!valid){
                cout<<"-1"<<endl;
                return;
            }
        }
    }
    for(int i=1;i<=N;i++){
    char ch=( psum[i]==0? '1':'0');
    ans.push_back(ch);
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t ;
     cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
