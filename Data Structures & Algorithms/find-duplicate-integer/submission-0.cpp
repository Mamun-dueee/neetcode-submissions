class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<bool> check(nums.size()+3, 0);

        for(int i = 0; i < nums.size(); i++){
            if(check[nums[i]] == true){
                return nums[i];
            }
            check[nums[i]] = true;
        }
        return 0;
        
    }
};
