class Solution 
{
    public:
    void solve(vector<vector<char>>& board) 
    {
        if (board.empty()) return;
    
        ROW = board.size();
        COL = board[0].size();
        visited.assign(ROW, vector<bool>(COL, false)); 
        
        // seed all border cell with 'O'
        // left col and right col
        for (int r=0; r<ROW; r++) {
            if (board[r][0] == 'O' && !visited[r][0]) {
                // write all border-connected Os to be Ts 
                dfs(r, 0, board);
            }
            if (board[r][COL-1] == 'O' && !visited[r][COL-1]) {
                dfs(r, COL-1, board);
            }
        }

        // top row and bottom row
        for (int c=0; c<COL; c++) {
            if (board[0][c] == 'O' && !visited[0][c]) {
                // write all border-connected Os to be Ts 
                dfs(0, c, board);
            }
            if (board[ROW-1][c] == 'O' && !visited[ROW-1][c]) {
                dfs(ROW-1, c, board);
            }
        }

        // those remaining Os should be X
        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                }
                if (board[r][c] == 'T') {
                    board[r][c] = 'O';
                }
            }
        }
    }
    private:
    int ROW, COL;
    vector<vector<bool>> visited;
    vector<pair<int, int>> DIRS = { {0,1}, {0,-1}, {1,0}, {-1,0} };

    void dfs(int row, int col, vector<vector<char>>& board)
    {
        visited[row][col] = true; 
        board[row][col] = 'T'; // need to be O later

        for (auto& DIR : DIRS) {
            int newR = row + DIR.first;
            int newC = col + DIR.second;

            if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
            if (visited[newR][newC]) continue;
            if (board[newR][newC] != 'O') continue;
            dfs(newR, newC, board);
        }
    }
};