class Solution 
{
    public:
    bool isMatch(string s, string p) 
    {
        int m = s.length(); //ROW
        int n = p.length(); //COL

        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

        for (int c=1; c<n+1; c++) {
            if (p[c-1] == '*') {
                dp[0][c] = dp[0][c-1];
            }
        }

        for (int r=0; r<m+1; r++) {
            for (int c=0; c<n+1; c++) {
                if (p[c-1] == '*') {
                    dp[r][c] = dp[r-1][c] || dp[r][c-1];
                } else if (p[c-1] == '?' || p[c-1] == s[r-1]) {
                    dp[r][c] = dp[r-1][c-1];
                } 
            }
        }
        
        return dp[m][n];
    }
};