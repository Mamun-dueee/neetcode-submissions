class Solution {
public:
    int cal(int a, int b, string t){
        if(t == "+"){
            return a+b;
        }
        else if(t == "-"){
            return a - b;
        }
        else if(t == "*"){
            return a*b;
        }
        else{
            return a/b;
        }
        return -1;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(string t : tokens){
            if(t == "+" || t == "*" || t == "-" || t == "/"){
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();
                stk.push(cal(a, b, t));
            }
            else{
                stk.push(stoi(t));
            }
        }
        return stk.top();
    }
};
