class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> new_s; 
        for(int i=0; i < s.size(); i++){ 
            if(isalnum(s[i])){
                char ch = tolower(s[i]);
                new_s.push_back(ch);
            }
        }
        int left = 0, right = new_s.size()-1;
        while(left < right){
            if(new_s[left] != new_s[right]){
                return false;
            }
            left++, right--;
        }
        return true;
    }
};