class Solution {
public:
    char getPair(char b){
        if(b == ')') return '(';
        if(b == '}') return '{';
        if(b == ']') return '[';
    }
    bool isValid(string s) {
        if(s.size()&1) return false;
        stack<char> stk; 
        for(char b : s){
            cout << b << " ";
            if(b == '(' || b == '{' || b == '['){
                stk.push(b);
            }
            else{
                if(stk.empty()){
                    return false;
                }
                if(stk.top() == getPair(b)){
                    stk.pop();
                }
                else{
                    return false;
                }
            }
        }
        return stk.empty();
        
    }
};
