class Solution 
{
    public:
    void solve(vector<vector<char>>& board) 
    {
        ROW = board.size();
        COL = board[0].size();
        visited.assign(ROW, vector<bool>(COL, false));

        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if ( (r==0 || r==ROW-1 || c==0 || c==COL-1) && board[r][c] == 'O') {
                    // should mark as 'T'
                    dfs(r, c, board);
                } 
            }
        }

        // flip all T back to O, and other Os to X
        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (board[r][c] == 'T') {
                    board[r][c] = 'O';
                } else if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                }
            }
        }
    }

    private:
    vector<pair<int, int>> DIRS = { {0,1}, {0,-1}, {1,0}, {-1,0} };
    vector<vector<bool>> visited;
    int ROW, COL;

    // board with 'T' is are originally the 'O's we cannot flip to 'T'
    void dfs(int row, int col, vector<vector<char>>& board)
    {
        visited[row][col] = true;
        board[row][col] = 'T';

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