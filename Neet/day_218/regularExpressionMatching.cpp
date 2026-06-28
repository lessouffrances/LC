class Solution 
{
    public:
    bool isMatch(string s, string p) 
    {
        int ROW = s.length()+1;
        int COL = p.length()+1;

        vector<vector<bool>>dp(ROW, vector<bool>(COL, false));
        dp[0][0] = true;

        // fill the first row
        for (int c=1; c<COL; c++) {
            if (p[c-1] == '*') {
                // "a*" => is empty
                dp[0][c] = dp[0][c-2];
            }
        }

        for (int r=1; r<ROW; r++) {
            for (int c=1; c<COL; c++) {
                if (p[c-1] == s[r-1] || p[c-1] == '.') {
                    dp[r][c] = dp[r-1][c-1];
                    continue;
                }

                if (p[c-1] == '*') {
                    dp[r][c] = dp[r][c-2];
                    // if prev char from p is a match with s[r-1], 
                    // shift upwards to include the possibility
                    if (p[c-2] == s[r-1] || p[c-2] == '.') {
                        dp[r][c] = dp[r][c] || dp[r-1][c];
                    }
                }
            }
        }
        return dp[ROW-1][COL-1];
    }
};