class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> win;
        int i = 0, j = 0, res = 0;
        while(j < s.size()){
            while(win.count(s[j]) > 0){
                win.erase(s[i]);
                i++;
            }
            win.insert(s[j]);
            j++;
            int cur_size = j - i;
            res = max(res, cur_size);
        }
        return res;
        
    }
};
