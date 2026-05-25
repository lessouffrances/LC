
// dfs on all the Os that are on the border
// These Os should remain, make them as T
// loop through each cell, change O to X, change T to O
class Solution 
{
    public:
    void solve(vector<vector<char>>& board) 
    {
        if (board.empty()) return;
        ROW = board.size();
        COL = board[0].size();

        // see borders
        for (int c=0; c<COL; c++) {
            if (board[0][c] == 'O') dfs(0, c, board);
            if (board[ROW-1][c] == 'O') dfs(ROW-1, c, board);
        } 
        for (int r=0; r<ROW; r++) {
            if (board[r][0] == 'O') dfs(r, 0, board);
            if (board[r][COL-1] == 'O') dfs(r, COL-1, board);
        } 

        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (board[r][c] == 'T') {
                    board[r][c] = 'O';
                } else if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                }
            }
        }
        return;
    }

    private:
    int ROW, COL;
    vector<pair<int, int>> DIRS = { {0,1}, {0,-1}, {-1,0}, {1,0} };
    void dfs(int row, int col, vector<vector<char>>& board)
    {
        board[row][col] = 'T';

        for (auto& DIR : DIRS) {
            int newR = row+DIR.first;
            int newC = col+DIR.second;

            if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
            if (board[newR][newC] != 'O') continue;
            dfs(newR, newC, board);
        }
    }
};