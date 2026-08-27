class Solution {
public:
    bool check(char ch){
        return ch == '+' || ch=='-' || ch == '*' || ch == '/';
    }
    int cal(int a, int b, char op){
        switch(op){
            case '+':
                return a + b;
                break;
            case '-':
                return a - b;
                break;
            case '*':
                return a * b;
                break;
            case '/':
                return a / b;
                break;
        }
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto x : tokens){
            if(x[0] == '-' && x.size() > 1){
                st.push(stoi(x));
                continue;
            }
            if(check(x[0])){
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                int res = cal(a, b, x[0]);
                st.push(res);
            }
            else{
                st.push(stoi(x));
            }
        }
        return st.top();
        
    }
};
