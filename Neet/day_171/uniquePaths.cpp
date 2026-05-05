// T: O(M * N)
// S: O(M * N)

class Solution 
{
    public:
    // m = ROW
    // n = COL
    int uniquePaths(int m, int n) 
    {
        if (m == 0 || n == 0) return 0;

        // make an empty grid
        vector<vector<int>> grid(m, vector<int>(n, 0));

        // fill the first row and first col to be 1
        for (int c=0; c<n; c++) {
            grid[0][c] = 1;
        }
        for (int r=0; r<m; r++) {
            grid[r][0] = 1;
        }

        for (int r=1; r<m; r++) {
            for (int c=1; c<n; c++) {
                grid[r][c] = grid[r][c-1] + grid[r-1][c];
            }
        }

        return grid[m-1][n-1];
    }
};