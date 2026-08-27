class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& board){
        if(r < 0 || r >= board.size() || c < 0 || c >= board[0].size()
            || board[r][c] != 'O'){
            return;
        }
        board[r][c] = '#';
        dfs(r-1, c, board);
        dfs(r+1, c, board);
        dfs(r, c+1, board);
        dfs(r, c-1, board);

    }
    void solve(vector<vector<char>>& board) {
        for(int r = 0; r < board.size(); r++){
            if(board[r][0] == 'O' ){
                dfs(r, 0, board);
            }
            if(board[r][board[0].size()-1] == 'O'){
                dfs(r, board[0].size()-1, board);
            }
        }
        for(int c = 0; c < board[0].size(); c++){
            if(board[0][c] == 'O' ){
                dfs(0, c, board);
            }
            if(board[board.size()-1][c] == 'O'){
                dfs(board.size()-1, c, board);
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
