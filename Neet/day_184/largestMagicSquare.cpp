class Solution 
{
    public:
    int largestMagicSquare(vector<vector<int>>& grid) 
    {
        if (grid.empty()) return 0;
        int ROW = grid.size();
        int COL = grid[0].size();

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
    // the r, c is the top-left corner
    bool isMagicSquare(vector<vector<int>>& grid, int r, int c, int k)
    {
        int target = 0;
        // sum first row as benchmark
        for (int i=c; i<c+k; i++) {
            target += grid[r][i];
        }

        // check all rows
        for (int i=r; i<r+k; i++) {
            int sum = 0;
            for (int j=c; j<c+k; j++) {
                sum += grid[i][j];
            }
            if (sum != target) return false;
        }

        // check all cols
        for (int j=c; j<c+k; j++) {
            int sum = 0;
            for (int i=r; i<r+k; i++) {
                sum += grid[i][j];
            }
            if (sum != target) return false;
        }

        // check all diags
        int diag1 = 0;
        int diag2 = 0;
        for (int i=0; i<k; i++) {
            diag1 += grid[r+i][c+i];
            diag2 += grid[r+i][c+k-1-i];
        }
        return diag1 == target && diag2 == target;
    }
};