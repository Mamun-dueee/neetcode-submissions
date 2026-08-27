class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp; // num -> count
        multimap<int, int> mp_cn;

        for(int n : nums){
            mp[n]++;
        }

        vector<int> ans;
        for(auto ii : mp){
            mp_cn.insert({ii.second, ii.first});
            //mp_cn[ii.second] = ii.first;
            //cout << ii.second << " " << ii.first << endl;
        }
        // for(auto ii: mp_cn)
        //     cout << ii.first << " " << ii.second << endl;
        auto it = mp_cn.rbegin();
        while(it != mp_cn.rend()){
            if(k == 0)
                break;
            ans.push_back((*it).second);
            k--;
            it++;
        }
        return ans;
        
    }
};
