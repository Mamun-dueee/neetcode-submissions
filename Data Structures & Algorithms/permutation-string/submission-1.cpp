class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()){
            return false;
        }
        unordered_map<char, int> mp1;
        for(char c : s1){
            mp1[c]++;
        }
        unordered_map<char, int> mp2;
        int winSz = s1.size();
        int r = 0;
        for(int i = 0; i <winSz; i++){
            mp2[s2[i]]++;
            r = i;
        }

        int l = 0; 
        while(r<s2.size()){
            if(mp1 == mp2){
                return true;
            }
            mp2[s2[l]]--;
            if(mp2[s2[l]] == 0){
                mp2.erase(s2[l]);
            }
            l++;
            r++;
            mp2[s2[r]]++;
            
        }
        
        return mp1==mp2;
        
    }
};