#include <iostream>
using namespace std;
int main(){
    string s;
    cout<<"Give me the string: ";
    cin>>s;
    int flag =0;
    for(char ch:s){
        flag|=(1<<(ch-'a'));
    }
    cout<<((flag==(1<<26)-1)?"yes":"no");
    return 0;
    }
