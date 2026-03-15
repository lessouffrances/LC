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
                if (board[r][c] == '.') {
                    // try each digit at this pos
                    for (int i=1; i<=9; i++) {
                        if (isValid(r, c, i, board)) {
                            board[r][c] = i+'0';
                            if (dfs(board)) return true;
                            board[r][c] = '.'; // backtrack
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(int row, int col, int digit, vector<vector<char>>& board) 
    {
        // check for the row
        for (int c=0; c<9; c++) {
            if (board[row][c] == digit+'0') return false;
        }

        // check for the col
        for (int r=0; r<9; r++) {
            if (board[r][col] == digit+'0') return false;
        }

        // check 3*3 square
        int boxTopLeftRow = 3 * (row / 3);
        int boxTopLeftCol = 3 * (col / 3);

        for (int i=0; i<9; i++) {
            int boxRow = boxTopLeftRow + (i / 3);
            int boxCol = boxTopLeftCol + (i % 3);

            if (board[boxRow][boxCol] == digit+'0') return false;
        }
        return true;
    }
};