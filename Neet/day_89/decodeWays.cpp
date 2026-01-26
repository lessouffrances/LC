class Solution
{
    public:
    int numDecodings(string s)
    {
        if (s.empty() || s[0] == '0') return 0;

        int n = s.length();
        vector<int>dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i=2; i<n+1; i++) {
            // substr starts at i-2 and with size 2
            string subDigits = s.substr(i-2, 2);
            // two adj zeros is invalid!
            if (subDigits == "00") return 0;

            if (subDigits[0] == '0') {
                dp[i] = dp[i-1];
                continue;
            } else if (subDigits[1] == '0') {
                if (stoi(subDigits) > 26) {
                    return 0;
                } else {
                    dp[i] = dp[i-2];
                    continue;
                }
            } else {
                if (stoi(subDigits) > 26) {
                    dp[i] = dp[i-1];
                    continue;
                } else {
                    dp[i] = dp[i-1] + dp[i-2];
                    continue;
                }
            }
        }

        return dp[n];
    }
};