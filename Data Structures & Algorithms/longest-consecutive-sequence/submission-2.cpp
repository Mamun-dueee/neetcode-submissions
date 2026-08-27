class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int res = 0; 
         
        for(int cur : nums){
            int curLongest = 0;
            while(st.find(cur) != st.end()){
                curLongest++;
                cur++;
            }
            res = max(res, curLongest);
        }
        return res;
    }
};