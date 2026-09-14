#include <iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    int l= s.length();
    for(int ch =1;ch<(1<<l);ch++){
        string combi=" ";
        for(int str=0;str<l;str++){
            if(ch&(1<<str)){
                combi+=s[str];
            }
        }cout<<combi<<endl;
    }
    return 0;
    }
