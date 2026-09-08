#include <bits/stdc++.h>
using namespace std;

void solve(){
    int N,K;
    cin>>N>>K;
    string s;
    cin>>s;
    int F= N/K;
    vector<bool> own(F,false);
    for(unsigned int i=0;i<s.length();i++){
        if(s[i]=='0'){
            int farmindex=i/K;
            own[farmindex]=true;
        }
    }
    
    int cnt=0;
    for(int f=0;f<F;f++){
        if(!own[f]){
            cnt++;
        }
    }
    
    cout<<cnt<<endl;
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
