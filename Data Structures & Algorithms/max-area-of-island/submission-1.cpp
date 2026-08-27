class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int dfs(int i, int j, vector<vector<int>>& grid){
        int r = grid.size(), c = grid[0].size();
        if(i<0 || j < 0 || i >= r || j >= c || grid[i][j] == 0){
            return 0;
        }
        grid[i][j] = 0; // visited
        int area = 1;
        // area += dfs(i+1, j, grid);
        // area += dfs(i-1, j, grid);
        // area += dfs(i, j+1, grid);
        // area += dfs(i, j-1, grid);
        for(int z = 0; z < 4; z++){
            area += dfs(i+dir[z][0], j+dir[z][1], grid);
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    int curArea = 0;
                    curArea = dfs(i, j, grid);
                    maxArea = max(maxArea, curArea);
                }
            }
        }
        return maxArea;
        
    }
};
