class Solution {
public:
    bool isBalanced(string num) {
        int evensum=0;
        int oddsum=0;
        for(int i=0;i<num.length();i++){
            int n= num[i]-'0';
            if(i%2==0){
                evensum+=n;
            }else{
                oddsum+=n;
            }
        }

        if(evensum==oddsum){
            return true;
        }
        return false;
    }
};