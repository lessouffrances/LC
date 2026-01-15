class Solution 
{
    public: 
    int longestCommonSubsequence(string text1, string text2) 
    {
        if (text1.empty() || text2.empty()) return 0;
        int ROW = text2.size();
        int COL = text1.size();

        vector<vector<int>> dp(ROW+1, vector<int>(COL+1, 0));
        for (int r=1; r<ROW+1; r++) {
            for (int c=1; c<COL+1; c++) {
                if (text1[c-1] == text2[r-1]) {
                    dp[r][c] = 1 + dp[r-1][c-1];
                } else {
                    dp[r][c] = max(dp[r-1][c], dp[r][c-1]);
                }
            }
        }
        return dp[ROW][COL];
    }
};