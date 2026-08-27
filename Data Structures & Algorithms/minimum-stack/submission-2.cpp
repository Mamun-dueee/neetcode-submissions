class MinStack {
    stack<pair<int, int>> stk; // {val, minVal}
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(stk.empty()){
            stk.push({val, val});
        }
        else{
            int prevMin = stk.top().second;
            int minVal = min(prevMin, val);
            stk.push({val, minVal});
        }
        
    }
    
    void pop() {
        stk.pop();
        
    }
    
    int top() {
        return stk.top().first;
        
    }
    
    int getMin() {
        return stk.top().second;
        
    }
};
