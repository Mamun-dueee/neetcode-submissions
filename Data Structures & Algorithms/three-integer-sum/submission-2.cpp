class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for(int i=0; i < len-2; i++){
            int j = i + 1;
            int k = len - 1;
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            while(j < k){
                if(nums[i]+nums[j]+nums[k] == 0){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    // searching for new res 
                    // for that we need to skip same numbers.
                    while(nums[k] == nums[k-1] && k > j){
                        k--;
                    }
                    while(nums[j] == nums[j+1] && j < k){
                        j++;
                    }
                    j++;
                    k--;
                    
                }
                else if(nums[i]+nums[j]+nums[k] > 0){
                    k--;
                }
                else{ // < 0
                    j++;
                }
            }
        }
        return ans; 
        
    }
};
