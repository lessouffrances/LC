


// strategy: reverse thinking;
// look at the border and do DFS on Os on the border and change all Os to T along the DFS
// then loop to see: the left Os that are remained to be O are surrounded region

class Solution 
{
    public:
    void solve(vector<vector<char>>& board) 
    {
        if (board.empty()) return;
        ROW = board.size();
        COL = board[0].size();

        // iterate thru the borders and dfs on Os on borders
        // left col && right col
        for (int r=0; r<ROW; r++) {
            if (board[r][0] == 'O') {
                dfs(r, 0, board);
            }
            if (board[r][COL-1] == 'O') {
                dfs(r, COL-1, board);
            }
        }
        // top && bottom row
        for (int c=1; c<COL-1; c++) {
            if (board[0][c] == 'O') {
                dfs(0, c, board);
            }
            if (board[ROW-1][c] == 'O') {
                dfs(ROW-1, c, board);
            }
        }

        // up to here
        // all the unsurrounded Os are marked as T
        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (board[r][c] == 'O') board[r][c] = 'X';

                // reverse the T back to O
                if (board[r][c] == 'T') board[r][c] = 'O';
            }
        }
    }
    private:
    int ROW, COL;
    vector<pair<int, int>> DIRS = { {0,1},{0,-1},{1,0},{-1,0} };
    void dfs(int row, int col, vector<vector<char>>& board)
    {
        board[row][col] = 'T'; // mark as T

        for (auto& DIR : DIRS) {
            int newR = row + DIR.first;
            int newC = col + DIR.second;

            if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
            if (board[newR][newC] != 'O') continue;
            dfs(newR, newC, board);
        }
    }
};
