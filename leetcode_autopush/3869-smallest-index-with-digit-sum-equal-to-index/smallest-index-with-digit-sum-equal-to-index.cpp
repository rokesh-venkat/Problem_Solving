class Solution {
public:
    int sumofdigit(int num){
        int sum=0;
        while(num>0){
            int d = num%10;
            sum+=d;
            num/=10;
        }

        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++){
            if(i==sumofdigit(nums[i])){
                return i;
            }
        }

        return -1;
    }
};