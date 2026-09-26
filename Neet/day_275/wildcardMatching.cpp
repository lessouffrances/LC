class Solution 
{
    public:
    bool isMatch(string s, string p) 
    {
        int ROW = s.length()+1;
        int COL = p.length()+1;

        vector<vector<bool>>dp(ROW, vector<bool>(COL, false));
        dp[0][0] = true; 

        // use the first row as base cases
        for (int c=1; c<COL; c++) {
            if (p[c-1] == '*') dp[0][c] = dp[0][c-1];
        }

        for (int r=1; r<ROW; r++) {
            for (int c=1; c<COL; c++) {
                // if chars are a match
                if (p[c-1] == s[r-1] || p[c-1] == '?') {
                    dp[r][c] = dp[r-1][c-1];
                    continue;
                }

                if (p[c-1] == '*') {
                    dp[r][c] = dp[r-1][c] || dp[r][c-1];
                }
            }
        }
        return dp[ROW-1][COL-1];
    }
};