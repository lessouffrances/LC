



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
        for (int c=1; c<COL; c++) {
            if (p[c-1] == '*') {
                dp[0][c] = dp[0][c-1];
            }
        }

        for (int r=1; r<ROW; r++) {
            for (int c=1; c<COL; c++) {
                // if the char is a match
                if (p[c-1] == s[r-1] || p[c-1] == '?') {
                    dp[r][c] = dp[r-1][c-1];
                    continue;
                }

                // if skip s prev or p prev
                if (p[c-1] == '*') {
                    dp[r][c] = dp[r-1][c] || dp[r][c-1];
                    // dp[r-1][c]: let * match the curr s char
                    // dp[r][c-1]: let * be empty
                    // either work
                }
            }
        }
        return dp[ROW-1][COL-1];
    }
};