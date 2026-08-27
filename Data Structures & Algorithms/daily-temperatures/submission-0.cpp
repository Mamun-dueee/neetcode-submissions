class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> res(temp.size(), 0);
        stack<pair<int, int>> st; // pair{temp, idx}

        for(int i = 0; i < temp.size(); i++){
            int t = temp[i];
            while(!st.empty() && t > st.top().first){
                auto preT = st.top();
                st.pop();
                res[preT.second] = i - preT.second;
            }
            st.push({t, i});
        }
        return res;
        
    }
};