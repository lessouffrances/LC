class Solution 
{
    public:
    int minDistance(string word1, string word2) 
    {
        int m = word1.length();
        int n = word2.length();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        // fill the first ROW with 1
        for (int c=0; c<=m; c++) {
            dp[0][c] = c;
        }
        // fill the first COL with 1
        for (int r=0; r<=n; r++) {
            dp[r][0] = r;
        }

        for (int r=1; r<=n; r++) {
            for (int c=1; c<=m; c++) {
                // if this char equal
                if (word1[c-1] == word2[r-1]) {
                    dp[r][c] = dp[r-1][c-1];
                } else {
                    dp[r][c] = 1+min( {dp[r-1][c-1], dp[r][c-1], dp[r-1][c]} );
                }
            }
        }
        return dp[n][m];
    }
};