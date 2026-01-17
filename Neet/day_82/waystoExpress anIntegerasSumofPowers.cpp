class Solution 
{
    public:
    int numberOfWays(int n, int x) 
    {
        const int MOD = 1e9 + 7;
        vector<int>dp(n + 1, 0);
        dp[0] = 1; // there is only one way to make 0

        for (int base=1; pow(base, x) <= n; base++) {
            int power = pow(base, x);

            // traverse backwards to avoid using the same number twice
            for (int sum=n; sum >= power; sum--) {
                dp[sum] = (dp[sum] + dp[sum - power]) % MOD;
            }

        }
        return dp[n];
    } 
};