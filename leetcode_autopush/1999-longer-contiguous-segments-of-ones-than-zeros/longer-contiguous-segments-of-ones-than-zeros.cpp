class Solution {
public:
    bool checkZeroOnes(string s) {
        int maxc =0;
        int count=0;
         int maxo =0;
        int counto=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                count++;
                counto=0;
            }else if(s[i]=='0'){
                counto++;
                count=0;

            }
            maxo = max(maxo,counto);
            maxc=max(maxc,count);
        }
       
       

    return maxc>maxo;
    }
};