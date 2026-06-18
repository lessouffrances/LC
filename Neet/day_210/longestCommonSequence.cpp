class Solution 
{
    public: 
    int longestCommonSubsequence(string text1, string text2) 
    {
        if (text1.empty() || text2.empty()) return "";

        int ROW = text2.length()+1;
        int COL = text1.length()+1;
        vector<vector<int>>dp(ROW, vector<int>(COL, 0));
        dp[0][0] = 0;

        for (int r=1; r<ROW; r++) {
            for (int c=1; c<COL; c++) {
                if (text2[r-1] == text1[c-1]) {
                    dp[r][c] = dp[r-1][c-1]+1;
                } else {
                    dp[r][c] = max(dp[r-1][c], dp[r][c-1]);
                }
            }
        }
        return dp[ROW-1][COL-1];
    }
};