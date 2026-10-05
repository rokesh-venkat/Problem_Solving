class Solution {
public:
    int scoreOfParentheses(string s) {
        int sum =0;
        int depth=0;
        for(int i =0;i<s.length();i++){
            if(s[i]=='('){
                depth++;
            }else if(s[i] == ')'){
                depth--;
            
            if(s[i-1]=='('){
                sum += (1<<depth);
            }
            }
        }
        return sum;
    }
};