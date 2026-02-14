class Solution 
{
    public:
    int numMagicSquaresInside(vector<vector<int>>& grid) 
    {
        if (grid.empty()) return 0;
        int ROW = grid.size();
        int COL = grid[0].size();

        int count = 0;
        for (int r=0; r<ROW-2; r++) {
            for (int c=0; c<COL-2; c++) {
                if (isMagicSquare(r, c, grid)) count++;
            }
        }
        return count;
    }
    private:
    bool isMagicSquare(int row, int col, vector<vector<int>>& grid)
    {
        int benchmark = 0;
        unordered_set<int> numSet;
        for (int i=1; i<=9; i++) {
            numSet.insert(i);
        }
        for (int r=row; r<=row+2; r++) {
            for (int c=col; c<=col+2; c++) {
                if (numSet.count(grid[r][c])) {
                    numSet.erase(grid[r][c]);
                } else {
                    return false; 
                }
            }
        }
        if (!numSet.empty()) return false; // not 1-9 distinct numbers in the square

        // sum up one row to get the benchmark sum
        for (int c=col; c<=col+2; c++) {
            benchmark += grid[row][c];
        }

        // check each row
        for (int r=row; r<=row+2; r++) {
            int rowSum = 0;
            for (int c=col; c<=col+2; c++) {
                rowSum += grid[r][c];
            }
            if (rowSum != benchmark) return false;
        }

        // check each col
        for (int c=col; c<=col+2; c++) {
            int colSum = 0;
            for (int r=row; r<=row+2; r++) {
                colSum += grid[r][c];
            }
            if (colSum != benchmark) return false;
        }

        // check diagonal
        int diagonal1 = grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2];
        if (diagonal1 != benchmark) return false;
        int diagonal2 = grid[row][col+2] + grid[row+1][col+1] + grid[row+2][col];
        if (diagonal2 != benchmark) return false;

        return true;
    }
};