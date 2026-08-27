class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        stack<pair<int, int>> stk; 
        vector<int> res(temps.size());

        for(int i = 0; i < temps.size(); i++){
            int t = temps[i];
            while(!stk.empty() && t > stk.top().first){
                int topIdx = stk.top().second;
                res[topIdx] = i - topIdx;
                stk.pop();
            }
            stk.push({t, i});
        }
        return res;
    }
};
