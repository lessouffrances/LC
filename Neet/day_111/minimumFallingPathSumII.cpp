









class Solution 
{
    public:
    int minFallingPathSum(vector<vector<int>>& grid) 
    {
        if (grid.empty()) return 0;
        int ROW = grid.size();
        int COL = grid[0].size();

        vector<vector<int>>dp(ROW, vector<int>(COL, 0));

        // fill the first row
        for (int c=0; c<COL; c++) {
            dp[0][c] = grid[0][c];
        }

        for (int r=1; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                int prevChoice = INT_MAX;
                for (int j=0; j<COL; j++) {
                    if (c == j) continue;
                    prevChoice = min(prevChoice, dp[r-1][j]);
                }
                dp[r][c] = grid[r][c] + prevChoice;
            }
        }
        
        // return
        int res = INT_MAX;
        for (int c=0; c<COL; c++) {
            res = min(res, dp[ROW-1][c]);
        }
        return res;
    }
};