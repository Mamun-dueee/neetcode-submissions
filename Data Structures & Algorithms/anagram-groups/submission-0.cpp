class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp; // base -> list of anagrams
        vector<vector<string>> ans; 
        
        for(auto s : strs){
            string p = s; // p will be pushed back. 
            sort(s.begin(), s.end());
            cout << s << " ";
            mp[s].push_back(p);
        }
        
        for(auto m : mp){
            ans.push_back(m.second);
        }
        return ans; 
    }
};
