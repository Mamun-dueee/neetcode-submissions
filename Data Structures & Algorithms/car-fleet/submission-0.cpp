class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        int n = position.size();

        for(int i = 0; i < n; i++){
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(), cars.end());

        float front_fleet_time, cur_fleet_time;
        front_fleet_time = (float)(target-cars[cars.size()-1].first)/cars[cars.size()-1].second;
        int res = 1;
        for(int i = cars.size()-1; i >= 0; i--){
            cur_fleet_time = (float) (target-cars[i].first) / cars[i].second;
                if(cur_fleet_time > front_fleet_time){
                    front_fleet_time = cur_fleet_time;
                    res++;
                }
        }
        return res;
    }
};
