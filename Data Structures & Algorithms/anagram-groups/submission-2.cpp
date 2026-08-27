class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<int>> mp;
        for(int i = 0; i < strs.size(); i++){
            string key = strs[i];
            sort(key.begin(), key.end());
            mp[key].push_back(i);
        }
        vector<vector<string>> res;
        for(auto m : mp){
            vector<string> cur; 
            for(int i : m.second){
                cur.push_back(strs[i]);
            }
            res.push_back(cur);
        }
        return res;
    }
};