class Solution 
{
    public:
    int numMagicSquaresInside(vector<vector<int>>& grid) 
    {
        int ROW = grid.size();
        int COL = grid[0].size();

        int count = 0;
        for (int r=0; r<=ROW-3; r++) {
            for (int c=0; c<=COL-3; c++) {
                if (isMagicGrid(grid, r, c)) count++;
            }
        }
        return count;
    }
    private:
    bool isMagicGrid(vector<vector<int>>& grid, int row, int col)
    {
        if (grid.empty()) return false;

        // check if all numbers are 1-9 distinct
        vector<bool>seen(10, false);
        for (int r=row; r<row+3; r++) {
            for (int c=col; c<col+3; c++) {
                int num = grid[r][c];
                if (num < 1 || num > 9 || seen[num]) {
                    return false;
                }
                seen[num] = true;
            }
        }

        int magicSum = grid[row][col] + grid[row][col+1] + grid[row][col+2];

        // check all rows
        for (int r=row; r<row+3; r++) {
            if (grid[r][col] + grid[r][col+1] + grid[r][col+2] != magicSum) return false;
        }

        // check all cols
        for (int c=col; c<col+3; c++) {
            if (grid[row][c] + grid[row+1][c] + grid[row+2][c] != magicSum) return false;
        }

        // check 2 diagonals
        if (grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2] != magicSum) return false;
        if (grid[row][col+2] + grid[row+1][col+1] + grid[row+2][col] != magicSum) return false;

        return true;
    }
};