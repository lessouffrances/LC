

class Solution 
{
    public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        if (triangle.empty()) return 0;

        vector<vector<int>> dp = triangle;
        int ROW = dp.size();

        // skip row 0
        for (int r=1; r<ROW; r++) {
            for (int c=0; c<dp[r].size(); c++) {
                // if at the ends of 1 row
                if (c == 0) {
                    dp[r][c] = triangle[r][c] + dp[r-1][c];
                    continue;
                } 
                if (c == dp[r].size()-1) {
                    dp[r][c] = triangle[r][c] + dp[r-1][c-1];
                    continue;
                }

                // if in between
                dp[r][c] = triangle[r][c] + min(dp[r-1][c], dp[r-1][c-1]);
            }
        }

        return *min_element(dp[ROW-1].begin(), dp[ROW-1].end());
    }
};