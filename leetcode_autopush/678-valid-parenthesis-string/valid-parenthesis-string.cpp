class Solution {
public:
    bool checkValidString(string s) {
        
        int maxcnt =0;
        int mincnt = 0;
        for(char ch : s){
            if(ch == '('){
                maxcnt++;
                mincnt++;
            }else if(ch == ')'){
                maxcnt--;
                mincnt--;
            }else{// ch == '*'
                mincnt--;
                maxcnt++;
            }

            if(maxcnt <0){
                return false;
            }

            if(mincnt<0){
                mincnt =0;
            }
        }

      return mincnt==0;
    }
};