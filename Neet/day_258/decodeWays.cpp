class Solution 
{
    public:
    int numDecodings(string s) 
    {
        if (s.length() == 0 || s[0] == '0') return 0;

        int n = s.length();
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i=2; i<n+1; i++) {
            // substr starts at i-2 and have a size of 2
            string digits = s.substr(i-2, 2);
            if (digits == "00") return 0;
            
            if (digits[0] == '0') {
                dp[i] = dp[i-1];
                continue;
            } else if (digits[1] == '0') {
                if (stoi(digits) > 26) {
                    return 0;
                } else {
                    dp[i] = dp[i-2];
                    continue;
                }
            } else {
                if (stoi(digits) > 26) {
                    dp[i] = dp[i-1];
                    continue;
                } else {
                    dp[i] = dp[i-1]+dp[i-2];
                    continue;
                }
            }
        }
        return dp[n];
    }
};
