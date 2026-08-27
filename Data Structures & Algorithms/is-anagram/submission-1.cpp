class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> cnt_s(26), cnt_t(26);

        for(char c : s){
            cnt_s[c-'a']++;
        }

        for(char c : t){
            cnt_t[c-'a']++;
        }

        if(cnt_s == cnt_t){
            return true;
        }
        return false;
        
    }
};
