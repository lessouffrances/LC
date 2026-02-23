class Solution 
{
    public:
    bool isMatch(string s, string p) 
    {
        int ROW = s.length()+1;
        int COL = p.length()+1;

        vector<vector<bool>> dp(ROW, vector<bool>(COL, false));
        dp[0][0] = true;

        // fill the first row
        // "a*" can be empty
        for (int c=2; c<COL; c++) {
            if (p[c-1] == '*') {
                dp[0][c] = dp[0][c-2];
            }
        }

        for (int r=1; r<ROW; r++) {
            for (int c=1; c<COL; c++) {
                // if char is match
                if (p[c-1] == '.' || p[c-1] == s[r-1]) {
                    dp[r][c] = dp[r-1][c-1];
                    continue;
                }

                if (p[c-1] == '*') {
                    // still, use * to match empty first
                    dp[r][c] = dp[r][c-2];

                    // if proceeding char is a match
                    if (p[c-2] == '.' || p[c-2] == s[r-1]) {
                        dp[r][c] = dp[r][c] || dp[r-1][c];
                    }
                }
            }
        }
        return dp[ROW-1][COL-1];
    }
};