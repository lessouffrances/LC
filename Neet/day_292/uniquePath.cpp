class Solution 
{
    public:
    int uniquePaths(int m, int n) 
    {
        if (m == 1 || n == 1) return 1;

        int ROW = m;
        int COL = n;
        vector<vector<int>> dp(ROW, vector<int>(COL, 1));

        // treat the first row and first col as base cases
        for (int r=1; r<ROW; r++) {
            for (int c=1; c<COL; c++) {
                dp[r][c] = dp[r-1][c] + dp[r][c-1];
            }
        }
        return dp[ROW-1][COL-1];
    }
};