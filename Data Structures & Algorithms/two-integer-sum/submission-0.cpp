class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // nums -> index
        
        for(int i=0; i<nums.size(); i++){
            int look = target - nums[i];
            if(mp.find(look) != mp.end()){
                return {min(i, mp[look]), max(i, mp[look])};
            }
            mp[nums[i]] = i; 
        }
        return {}; 
    }
};
