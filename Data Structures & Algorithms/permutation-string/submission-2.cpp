class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        vector<int> v1(26), v2(26);
        for(int i = 0; i < s1.size(); i++){
            v1[s1[i]-'a']++;
            v2[s2[i]-'a']++;
        }
        if(v1 == v2){
            return true;
        }
        for(int i = s1.size(), l = 0; i < s2.size(); i++, l++){
            v2[s2[l]-'a']--;
            v2[s2[i]-'a']++;
            if(v1 == v2){
                return true;
            }
        }
        return v1==v2;
    }
};