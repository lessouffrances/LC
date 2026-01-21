class Solution 
{
    public:
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>>grid(m, vector<int>(n, 0));

        // fill the bottom row and right col with 1
        // m -> ROW, n -> COL
        for (int r=0; r<m; r++) {
            grid[r][n-1] = 1;
        }  
        for (int c=0; c<n; c++) {
            grid[m-1][c] = 1;
        }   
        
        for (int r=m-2; r>=0; r--) {
            for (int c=n-2; c>=0; c--) {
                grid[r][c] = grid[r+1][c] + grid[r][c+1];
            }
        }
        return grid[0][0];
    }
};