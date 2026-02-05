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
            // substr starts at idx i-2 and size of 2
            string digits = s.substr(i-2, 2);
            if (digits == "00") return 0;

            if (digits[0] == '0') { // 09
                dp[i] = dp[i-1];
                continue;

            } else if (digits[1] == '0') { // 10 or 30
                if (stoi(digits) > 26) {
                    return 0;
                } else {
                    dp[i] = dp[i-2];
                    continue;
                }

            } else {
                if (stoi(digits) > 26) { // 36
                    dp[i] = dp[i-1];
                    continue;
                } else { // 14
                    dp[i] = dp[i-2]+dp[i-1];
                    continue;
                }
            }
        }
        
        return dp[n]; 
    }
};