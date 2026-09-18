class Solution 
{
    public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int ROW = grid.size();
        int COL = grid[0].size();

        // from (0, 0) to this coords, what is the minPathSum?
        vector<vector<int>> dp(ROW, vector<int>(COL, 0));

        // base cases: top row and left col
        dp[0][0] = grid[0][0];
        for (int c=1; c<COL; c++) {
            dp[0][c] = dp[0][c-1]+grid[0][c];
        }
        for (int r=1; r<ROW; r++) {
            dp[r][0] = dp[r-1][0]+grid[r][0];
        }

        for (int r=1; r<ROW; r++) {
            for (int c=1; c<COL; c++) {
                dp[r][c] = min( dp[r-1][c], dp[r][c-1] ) + grid[r][c];
            }
        }
        return dp[ROW-1][COL-1];
    }
};