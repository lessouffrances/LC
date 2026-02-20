class Solution 
{
    public:
    void solveSudoku(vector<vector<char>>& board) 
    {
        if (board.empty()) return;
        ROW = board.size();
        COL = board[0].size();
        dfs(board);
    }
    private:
    int ROW, COL;
    bool dfs(vector<vector<char>>& board)
    {
        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (board[r][c] == '.') {
                    // try each digit
                    for (int i=1; i<=9; i++) {
                        if (isValid(r, c, i, board)) {
                            board[r][c] = i + '0';
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
        // check the row
        for (int c=0; c<COL; c++) {
            if (board[row][c] == digit + '0') return false;
        }
        // check the col
        for (int r=0; r<ROW; r++) {
            if (board[r][col] == digit + '0') return false;
        }

        // check the box
        int boxTopLeftRow = 3 * (row/3);
        int boxTopLeftCol = 3 * (row/3);

        for (int i=0; i<9; i++) {
            int boxRow = boxTopLeftRow + (i / 3);
            int colRow = boxTopLeftCol + (i % 3);

            if (board[boxRow][boxCol] == digit + '0') return false;
        }
        return true;
    }
};
