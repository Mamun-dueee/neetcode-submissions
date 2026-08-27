class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp1, mp2;
        for(char c : s1){
            mp1[c]++;
        }
        int winSz = s1.size();

        for(int i = 0; i < winSz; i++){
            mp2[s2[i]]++;
        }

        if(mp1 == mp2) return true;

        for(int i = 1, j = winSz; j < s2.size(); i++, j++){
            mp2[s2[i-1]]--;
            if(mp2[s2[i-1]] == 0){
                mp2.erase(s2[i-1]);
            }
            mp2[s2[j]]++;
            if(mp1 == mp2){
                return true;
            }
            // cout << "map1:"<<endl;
            // for(auto m : mp1){
            //     cout << m.first << " " << m.second << endl; 
            // }
            // cout << "map2:"<<endl;
            // for(auto m : mp2){
            //     cout << m.first << " " << m.second << endl; 
            // }
        }
        return false;
        
    }
};
