class Solution {
    vector<string> res; 
public:
    vector<string> generateParenthesis(int n) {
        string curString = "";
        backtrack(curString, 0, 0, n);
        return res; 
        
    }
    void backtrack(string& curString, int open, int close, int n){
        if(open == n && open == close){
            res.push_back(curString);
            return;
        }
        if(open < n){
            curString += '(';
            backtrack(curString, open+1, close, n);
            curString.pop_back();
        }
        if(close < open){
            curString += ')';
            backtrack(curString, open, close+1, n);
            curString.pop_back();
        }
    }
};
