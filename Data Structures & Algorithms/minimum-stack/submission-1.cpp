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
            int pre_min = stk.top().second;
            pre_min = min(pre_min, val);
            stk.push({val, pre_min});
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
