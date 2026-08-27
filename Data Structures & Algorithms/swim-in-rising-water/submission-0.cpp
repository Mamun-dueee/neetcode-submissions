class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size();
        set<pair<int, int>> visit;
        priority_queue<vector<int>,
            vector<vector<int>>, greater<>> minHeap;
        vector<vector<int>> directions = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}
        };

        minHeap.push({grid[0][0], 0, 0}); // t, r, c
        visit.insert({0, 0});

        while(!minHeap.empty()){
            auto cur = minHeap.top();
            minHeap.pop();
            int t = cur[0], r = cur[1], c = cur[2];
            if(r == N-1 && c == N-1){
                return t;
            }
            for(auto dir : directions){
                int neiR = r+dir[0], neiC = c+dir[1];
                if(neiR < 0 || neiC < 0 || neiR == N ||
                neiC == N || visit.count({neiR, neiC})){
                    continue;
                }
                visit.insert({neiR, neiC});
                minHeap.push({
                    max(t, grid[neiR][neiC]), neiR, neiC
                });
            }
        }
        return -1;
        
    }
};
