class Solution {
public:
    vector<vector<string>> res; 
    bool isPalin(string s){
        int l = 0, r = s.size()-1;
        while(l < r){
            if(s[l] != s[r]){
                return false;
            }
            l++; 
            r--;
        }
        return true;
    }
    void dfs(string s, vector<string> &partions){
        if(s == ""){
            res.push_back(partions);
            return;
        }
        for(int i = 1; i <= s.size(); i++){
            string parts;
            parts = s.substr(0, i);
            if(isPalin(parts)){
                partions.push_back(parts);
                dfs(s.substr(i), partions);
                partions.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> partions;
        dfs(s, partions);
        return res;
    }
};
