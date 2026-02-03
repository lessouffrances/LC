







class Solution 
{
    public:
    int numMagicSquaresInside(vector<vector<int>>& grid) 
    {
        if (grid.empty()) return 0;

        int ROW = grid.size();
        int COL = grid[0].size();

        int count = 0;
        for (int r=0; r<=ROW-3; r++) {
            for (int c=0; c<=COL-3; c++) {
                if (isMagicSquare(grid, r, c)) count++;
            }
        }

        return count;
    }
    private:
    bool isMagicSquare(vector<vector<int>>& grid, int row, int col)
    {
        if (grid.empty()) return false;

        // condition 1: if all numbers are 1-9 distinct
        unordered_set<int> seen;
        for (int r=row; r<row+3; r++) {
            for (int c=col; c<col+3; c++) {
                int num = grid[r][c];
                if (num < 1 || num > 9 || seen.count(num)) {
                    return false;
                }
                seen.insert(num);
            }
        }

        // reference sum
        int sum = grid[row][col] + grid[row][col+1] + grid[row][col+2];

        // check if all rows have the same sum
        for (int r=row; r<row+3; r++) {
            int currRowSum = grid[r][col] + grid[r][col+1] + grid[r][col+2];
            if (currRowSum != sum) return false;
        }
        // check if all cols have the same sum
        for (int c=col; c<col+3; c++) {
            int currRowSum = grid[row][c] + grid[row+1][c] + grid[row+2][c];
            if (currRowSum != sum) return false;
        }
        // check if 2 diagonals has the same sum
        int diag1 = grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2];
        if (diag1 != sum) return false;
        int diag2 = grid[row+2][col] + grid[row+1][col+1] + grid[row][col+2];
        if (diag2 != sum) return false;

        return true;
    }
};