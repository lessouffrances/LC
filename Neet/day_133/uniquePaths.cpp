



// Time: O( M * N)
// Space: O( M * N)
class Solution 
{
    public:
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // fill the top row and left col
        for (int c=0; c<n; c++) {
            dp[0][c] = 1;
        } 
        for (int r=0; r<m; r++) {
            dp[r][0] = 1;
        }

        for (int r=1; r<m; r++) {
            for (int c=1; c<n; c++) {
                dp[r][c] = dp[r-1][c] + dp[r][c-1];
            }
        }
        return dp[m-1][n-1];
    }
};