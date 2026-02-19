class Solution 
{
    public:
    int longestPalindromeSubseq(string s) 
    {
        if (s.length() == 0) return 0;
        int n = s.length();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // single char as base case
        for (int i=0; i<n; i++) {
            dp[i][i] = 1;
        }

        for (int len=2; len<=n; len++) {
            for (int start=0; start<=n-len; start++) {
                int end = start + len - 1;

                if (s[start] == s[end]) {
                    dp[start][end] = dp[start+1][end-1] + 2; // length
                } else {
                    dp[start][end] = max(dp[start][end-1], dp[start+1][end]);
                }
            }
        }
        return dp[0][n-1];
    }
};