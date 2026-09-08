#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    int N;
    cin>>N;
    vector<int> arr(N);
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    int left=0,right=N-1;
    while(left<N && arr[left]==0) {
        left++;
    }
    while(right>=0 && arr[right]==0){
         right--;
    }
    
    if(left<=right){
        for(int i=left+1;i<right;i++){
            if(arr[i]==-1) arr[i]=0;
        }
        arr[left] = arr[right]=1;
    }
    
    for(int i=0;i<N;i++){
        cout<<arr[i]<<(i==N-1?"\n":" ");
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
