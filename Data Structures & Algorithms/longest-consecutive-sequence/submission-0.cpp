class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0; 
        unordered_set<int>  st(nums.begin(), nums.end());
         
        for(int n : nums){
            int cur = n; 
            int streak = 0;
            while(st.find(cur) != st.end()){
                streak++;
                cur++;
            }
            res = max(res, streak);
        }
        return res;
    }
};
