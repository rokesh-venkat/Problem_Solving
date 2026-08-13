#include <bits/stdc++.h>
using namespace std;

void solve(){
   int L,Q;
   cin>>L>>Q;
   set<int> st;
   st.insert(0);
   st.insert(L);
   while(Q--){
     int q,x;
     cin>>q>>x;
     if(q == 1){
       st.insert(x);
     }else{
       auto it = st.upper_bound(x);
       cout<<*it- *(prev(it))<<endl;
     }
   }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}