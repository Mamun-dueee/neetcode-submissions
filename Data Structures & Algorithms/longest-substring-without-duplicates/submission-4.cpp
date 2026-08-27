class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        int res = 0;
        unordered_set<char> st;
        while(r < s.size()){
            //delete char
            while(st.find(s[r]) != st.end()){
                st.erase(s[l]);
                l++;
            }

            //insert char
            st.insert(s[r]);
            r++;
            res = max(res, (int)st.size());
        }
        return res;
    }
};