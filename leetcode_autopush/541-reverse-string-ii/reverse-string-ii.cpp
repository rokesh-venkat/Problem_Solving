class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i=0;i<s.length();i+= 2*k){
            reverse(s.begin()+i,s.begin()+min((int)s.length(),i+k));
        }
        return s;
    }
};