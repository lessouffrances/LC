class Solution 
{
    public:
    int numDistinct(string s, string t) 
    {
        if (s.length() < t.length()) return 0;
        int m = s.length(); //COL
        int n = t.length(); //ROW

        vector<vector<unsigned long long>> dp(n+1, vector<unsigned long long>(m+1, 0));
        // pad first row and col with 0
        for (int r=0; r<n+1; r++) {
            dp[r][0] = 0;
        }
        for (int c=0; c<m+1; c++) {
            dp[0][c] = 1;
        }

        for (int r=1; r<n+1; r++) {
            for (int c=1; c<m+1; c++) {

                dp[r][c] = dp[r][c-1];

                if (s[c-1] == t[r-1]) {
                    dp[r][c] += dp[r-1][c-1];
                }
            }
        }

        return (int)dp[n][m];
    }
};