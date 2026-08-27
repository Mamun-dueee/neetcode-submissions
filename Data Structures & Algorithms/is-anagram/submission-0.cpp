class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        vector<int> sv(26, 0), tv(26, 0);

        for(char c : s){
            sv[c-'a']++;
        }
        for(char c : t){
            tv[c-'a']++;
        }

        return sv==tv;
        
    }
};
