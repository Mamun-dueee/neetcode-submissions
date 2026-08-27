class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<int>> mp;

        for(int i = 0; i < strs.size(); i++){
            string indx = strs[i];
            sort(indx.begin(), indx.end()); 
            mp[indx].push_back(i);
        }
        vector<vector<string>> res;

        for(auto m : mp){
            vector<int> id = m.second;
            vector<string> cur; 
            for(int i : id){
                cur.push_back(strs[i]);
            }
            res.push_back(cur);
        }
        return res;
    }
};
