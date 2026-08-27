class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size()-1;

        while(l < r){
            while(!isalnum(s[l]) && l < r) l++;
            while(!isalnum(s[r]) && r > l) r--;

            char leftChar = tolower(s[l]);
            char rightChar = tolower(s[r]);

            cout << leftChar << " " << rightChar << endl;

            if(leftChar != rightChar){
                return false;
            }
            l++, r--;
        }
        return true;
    }
};
