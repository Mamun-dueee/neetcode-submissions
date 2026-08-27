class Solution {
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        queue<pair<int, int>> q; 
        for(int r = 0; r < ROWS; r++){
            for(int c = 0; c < COLS; c++){
                if(grid[r][c] == 2){
                    q.push({r, c});
                }
            }
        }

        //start bfs
        int time = 0;
        while(!q.empty()){
            int level = q.size();
            for(int l = 0; l < level; l++){
                auto curCell = q.front();
                q.pop();
                int r = curCell.first, c = curCell.second;

                for(auto dir : dirs){
                    int nr = r + dir[0], nc = c + dir[1];

                    if(nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS
                        && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                    }
                }
            }
            time++;
            cout << level << " " << time << endl; 
        }
        for(int r = 0; r < ROWS; r++){
            for(int c = 0; c < COLS; c++){
                if(grid[r][c] == 1){
                    return -1;
                }
            }
        }

        return (time == 0) ? time : time - 1; 

        
    }
};
