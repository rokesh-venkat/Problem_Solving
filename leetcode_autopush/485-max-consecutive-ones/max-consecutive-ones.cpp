class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max1=0,count =0;
        for(int n : nums){
            if(n==1){
                count++;
            }else{
                count=0;
            }
            max1=max(max1,count);
            
        }
        return max1;
    }
};