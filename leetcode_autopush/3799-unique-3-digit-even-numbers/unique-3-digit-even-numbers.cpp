class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> unique;
        int len= digits.size();
        for(int i=0;i<len;i++){
            if(digits[i]==0){
                continue;
            }

            for(int j=0;j<len;j++){
                if(j==i){
                    continue;
                }

                for(int k=0;k<len;k++){
                    if(k==i||k==j){
                        continue;
                    }

                    int one = digits[k];
                    if(one%2!=0){
                        continue;
                    }
                    int hund = digits[i];
                    int ten = digits[j];
                    int num = hund*100 + ten*10+one;
                    unique.insert(num);


                }
            }
        }
        return unique.size();
    }
};