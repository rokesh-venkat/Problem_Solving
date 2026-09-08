class Solution {
public:
    string toLowerCase(string s) {
        for(int i=0;i<s.length();i++){
            char c= s[i];
            if(isupper(c)){
                s[i]= c+32;
            }
        }
        return s;
    }
};