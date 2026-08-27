class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res; 
        unordered_map<int, int> mp;
        for(int n : nums){
            mp[n]++;
        }
        priority_queue<pair<int, int>> pq;
        for(auto m : mp){
            pq.push({m.second, m.first});
        }
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
