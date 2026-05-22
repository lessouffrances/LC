// T: O(M * N * k^3)
// S: O(1)

class Solution 
{
    public:
    int largestMagicSquare(vector<vector<int>>& grid) 
    {
        if (grid.empty()) return 0;
        int ROW = grid.size();
        int COL = grid[0].size();

        // iterate every possible solution from large k to small k
        // greedy
        for (int k=min(ROW, COL); k>=2; k--) {
            for (int r=0; r+k<=ROW; r++) {
                for (int c=0; c+k<=COL; c++) {
                    if (isMagicSquare(grid, r, c, k)) return k;
                }
            }
        }
        return 1;
    }
    private:
    // use the r and c as the top-left corner
    bool isMagicSquare(vector<vector<int>>& grid, int r, int c, int k)
    {
        // compute benchmark using the first row
        int sum = 0;
        for (int i=c; i<c+k; i++) {
            sum += grid[r][i];
        }

        // check all rows
        for (int i=r; i<r+k; i++) {
            int rowSum = 0;
            for (int j=c; j<c+k; j++) {
                rowSum += grid[i][j];
            }
            if (rowSum != sum) return false;
        }

        // check all cols
        for (int j=c; j<c+k; j++) {
            int colSum = 0;
            for (int i=r; i<r+k; i++) {
                colSum += grid[i][j];
            }
            if (colSum != sum) return false;
        }

        // check all diags
        int diag1 = 0;
        int diag2 = 0;
        for (int i=0; i<k; i++) {
            diag1 += grid[r+i][c+i];
            diag2 += grid[r+i][c+k-i-1];
        }
        return diag1 == sum && diag2 == sum;
    }
};