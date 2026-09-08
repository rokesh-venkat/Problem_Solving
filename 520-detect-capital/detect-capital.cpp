class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt =0;
        int len = word.length();

        if(isupper(word[0])){
            for(int i=0;i<len;i++){
                if(isupper(word[i])){
                    cnt++;
                }
            }

            if(cnt==1||cnt==len){
                return true;
            }
        }

        if(islower(word[0])){
            for(int i=0;i<len;i++){
                if(islower(word[i])){
                    cnt++;
                }
            }

            if(cnt==len){
                return true;
            }
        }

        return false;
    }
};