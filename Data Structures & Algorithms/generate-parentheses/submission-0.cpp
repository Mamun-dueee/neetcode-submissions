class Solution {
    vector<string> res; 
public:
    bool isValid(string s){
        int open = 0;
        for(char c : s){
            open += (c == '(') ? 1 : -1;
            if(open < 0){
                return false;
            }
        }
        return open == 0;
    }
    vector<string> generateParenthesis(int n) {
        string cur = "";
        dfs(n, cur);
        return res;
    }
    void dfs(int n, string cur){
        if(cur.size() == 2*n){
            if(isValid(cur)){
                res.push_back(cur);
            }
            return;
        }
        cur += "(";
        dfs(n, cur);
        cur.pop_back();
        cur += ")";
        dfs(n, cur);
    }
};
