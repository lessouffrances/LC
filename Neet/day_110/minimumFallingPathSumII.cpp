class Solution 
{
    public:
    int minFallingPathSum(vector<vector<int>>& grid) 
    {
        if (grid.empty()) return 0;
        int n = grid.size();

        vector<vector<int>>dp(n, vector<int>(n, 0));
        // fill the first row
        for (int c=0; c<n; c++) {
            dp[0][c] = grid[0][c];
        }

        for (int r=1; r<n; r++) {
            for (int c=0; c<n; c++) {
                int prevChoice = INT_MAX;
                for (int j=0; j<n; j++) {
                    if (j == c) continue;
                    prevChoice = min( prevChoice, dp[r-1][j] );
                }
                dp[r][c] = grid[r][c] + prevChoice;
            }
        }

        // return
        int minFallingPathSum = INT_MAX;
        for (int c=0; c<n; c++) {
            minFallingPathSum = min(minFallingPathSum, dp[n-1][c]);
        }
        return minFallingPathSum;
    }
};