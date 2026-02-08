





class Solution 
{
    public:
    void solveSudoku(vector<vector<char>>& board) 
    {
        dfs(board);
    }
    private:
    bool dfs(vector<vector<char>>& board)
    {
        for (int r=0; r<9; r++) {
            for (int c=0; c<9; c++) {
                // find empty cell
                if (board[r][c] == '.') {
                    // try numbers 1 - 9
                    for (char digit = '1'; digit<='9'; digit++) {
                        if (isValid(board, r, c, digit)) {
                            board[r][c] = digit;

                            if (dfs(board)) return true;
                            board[r][c] = '.'; // backtrack
                        }
                    }
                    return false; // no digit can solve 
                }
            }
        }
        return true;
    }
    bool isValid(vector<vector<char>>& board, int row, int col, int digit)
    {
        for (int i=0; i<9; i++) {
            // check the row
            if (board[row][i] == digit) return false;

            // check the col
            if (board[i][col] == digit) return false;

            int boxRow = 3 * (row / 3) + i / 3;
            int boxCol = 3 * (col / 3) + i % 3;

            if (board[boxRow][boxCol] == digit) return false;
        }
        return true;
    }
};