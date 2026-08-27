class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        vector<pair<int, int>> ps; // {pos, spd}
        for(int i = 0; i < pos.size(); i++){
            ps.push_back({pos[i], speed[i]});
        }
        sort(ps.begin(), ps.end());
        int n = ps.size();

        float tPrev = 0;
        int fleet = 0;
        for(int i = n-1; i >= 0; i--){
            float tCur = (float)(target - ps[i].first) / ps[i].second;
            if(tCur > tPrev){
                fleet++;
                tPrev = tCur;
            }
        }
        return fleet;
    }
};
