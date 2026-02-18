class Solution 
{
    public:
    int numDistinct(string s, string t) 
    {
        if (s.length() < t.length()) return 0;
        int ROW = t.length()+1;
        int COL = s.length()+1;

        vector<vector<unsigned long long>>dp(ROW, vector<unsigned long long>(COL, 0));
        
        // fill the first row
        for (int c=0; c<COL; c++) {
            dp[0][c] = 1;
        }

        for (int r=1; r<ROW; r++) {
            for (int c=1; c<COL; c++) {
                // do not use the char
                dp[r][c] = dp[r][c-1];

                if (t[r-1] == s[c-1]) {
                    dp[r][c] += dp[r-1][c-1];
                }
            }
        }
        return dp[ROW-1][COL-1];
    }
};