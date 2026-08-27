class Solution {
public:
    bool isPalindrome(string s) {
        string sNew = "";
        for(char c : s){
            if(isalnum(c)){
                sNew += tolower(c);
            }
        }
        int n = sNew.size();

        int l = 0, r = n-1;
        while(l < r){
            if(sNew[l] != sNew[r]){
                return false;
            }
            l++, r--;
        }
        return true;
        
    }
};
