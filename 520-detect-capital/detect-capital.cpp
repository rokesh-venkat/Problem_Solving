class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt =0;
        int len = word.length();

        for(char c: word){
            if(isupper(c)){
                cnt++;
            }
        }

        if(cnt==1 && isupper(word[0])){
            return true;
        }else if(cnt == len){
            return true;
        }else if(cnt ==0){
            return true;
        }

         return false;
    }
};