class Solution {
public:
    set<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> cur;
        backtrack(nums, target, 0, cur, 0);
        return vector<vector<int>>(res.begin(), res.end());
    }

    void backtrack(vector<int>& nums, int target, int i, vector<int>& cur, int total){
        if(total == target){
            res.insert(cur);
            return;
        }
        if(total > target || i == nums.size()){
            return;
        }

        cur.push_back(nums[i]);
        backtrack(nums, target, i+1, cur, total+nums[i]);
        cur.pop_back();

        while(i+1 < nums.size() && nums[i] == nums[i+1]){
            i++;
        }

        backtrack(nums, target, i+1, cur, total);
    }
};
