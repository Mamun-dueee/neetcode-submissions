class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int mul = 1, zeroCnt = 0;
        for(int i : nums){
            if(i == 0){
                zeroCnt++;   
            }
            else{
                mul *= i;
            }
        }
        if(zeroCnt > 1){
            for(int i = 0; i < nums.size(); i++)
                nums[i] = 0;

            return nums;
        }
        if(zeroCnt == 1){
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] == 0) nums[i] = mul;
                else nums[i] = 0; 
            }
            return nums;
        }

        for(int i = 0; i < nums.size(); i++){
            nums[i] = mul / nums[i];
        }
        return nums;

    }
};
