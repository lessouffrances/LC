class Solution 
{
    public:
    int uniquePaths(int m, int n) 
    {
        // init a dp table
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // fill the bottom row and right col with 1
        for (int r=0; r<m; r++) {
            dp[r][n-1] = 1;
        }
        for (int c=0; c<n; c++) {
            dp[m-1][c] = 1;
        }
        for (int r=m-2; r>=0; r--) {
            for (int c=n-2; c>=0; c--) {
                dp[r][c] = dp[r+1][c] + dp[r][c+1];
            }
        }
        return dp[0][0];
    }
};
