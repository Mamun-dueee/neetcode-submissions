class Solution {
public:
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0,1}, {0, -1}};
    void solve(vector<vector<char>>& board) {
        queue<pair<int, int>> q;
        for(int r = 0; r < board.size(); r++){
            if(board[r][0] == 'O' ){
                q.push({r, 0});
            }
            if(board[r][board[0].size()-1] == 'O'){
                q.push({r, board[0].size()-1});
            }
        }
        for(int c = 0; c < board[0].size(); c++){
            if(board[0][c] == 'O' ){
                q.push({0, c});
            }
            if(board[board.size()-1][c] == 'O'){
                q.push({board.size()-1, c});
            }
        }

        while(!q.empty() ){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            board[r][c] = '#';

            for(auto dir : dirs){
                int nr = r + dir.first;
                int nc = c + dir.second;

                if(nr < 0 || nr >= board.size() || nc < 0 || nc >= board[0].size()
                    || board[nr][nc] != 'O'){
                    continue;
                }
                q.push({nr, nc});
                
            }
        }

        for(int r = 0; r < board.size(); r++){
            for(int c = 0; c < board[0].size(); c++){
                if(board[r][c] == 'O'){
                    board[r][c] = 'X';
                }
                if(board[r][c] == '#'){
                    board[r][c] = 'O';
                }
            }
        }
        
    }
};
