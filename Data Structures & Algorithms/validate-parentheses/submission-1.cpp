class Solution {
public:
    bool isValid(string s) {
        stack<char> st; 

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }
            else{ // closing bracket
                if(st.empty()){
                    return false;
                }
                char check = st.top();
                st.pop();
                if(s[i] == ')'){
                    if(check != '(') return false;
                }
                if(s[i] == '}' && check != '{'){
                    return false;
                }
                if(s[i] == ']' && check != '['){
                    return false;
                }
            }
        }

        if(st.empty()) return true;

        return false;
        
    }
};
