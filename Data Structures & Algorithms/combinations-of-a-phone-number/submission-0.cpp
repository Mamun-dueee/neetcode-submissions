class Solution {
public:
    vector<string> res;
    vector<string> numToChar = {"","", "abc", "def", "ghi", "jkl", "mno", 
            "pqrs", "tuv", "wxyz"};

    void bkt(int i, string cur, string& digits){
        //base case
        if(cur.size() == digits.size()){
            res.push_back(cur);
            return;
        }
        //recurse
        string totalChars = numToChar[digits[i]-'0'];
        for(char c : totalChars){
            bkt(i+1, cur+c, digits);
        }
        
    }
    vector<string> letterCombinations(string digits) {
        if(digits == ""){
            return res;
        }
        bkt(0, "", digits);
        return res;
    }
};
