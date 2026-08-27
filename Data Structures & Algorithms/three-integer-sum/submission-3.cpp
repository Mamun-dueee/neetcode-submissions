class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size()-2; i++){
            if(i > 0 && nums[i-1] == nums[i]){
                continue;
            }
            int j = i+1, k = nums.size()-1;
            while(j < k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == 0){
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++, k--;
                    while(j<k && nums[j-1] == nums[j]){
                        j++;
                    }
                }
                else if(sum > 0){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return res;
        
    }
};