class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int res = 0;
        for(int l = 0, r = 0; r < s.size(); r++){
            while(st.find(s[r]) != st.end()){
                st.erase(s[l++]);
            }
            st.insert(s[r]);
            res = max(res, (int)st.size());
        }
        return res; 
        
    }
};
