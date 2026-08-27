class Solution {
public:
    double distFromOrigin(int x, int y){
        return sqrt(x*x + y*y);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<float, int>> pq;

        for(int i = 0; i < points.size(); i++){
            auto p = points[i];
            float dist = distFromOrigin(p[0], p[1]);
            pq.push({dist, i});
            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<vector<int>> res; 

        while(!pq.empty()){
            res.push_back(points[pq.top().second]);
            pq.pop();
        }

        return res;
    }
};
