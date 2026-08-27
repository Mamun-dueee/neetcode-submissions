class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        int res = 0;
        unordered_map<char, int> mp;
        while(r < s.size()){
            if(mp.find(s[r]) != mp.end()){
                l = max(l, mp[s[r]]+1);
            }
            mp[s[r]] = r;
            res = max(res, r-l+1);
            r++;
        }
        return res;
    }
};