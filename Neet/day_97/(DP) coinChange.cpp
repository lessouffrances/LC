class Solution 
{
    public:
    int coinChange(vector<int>& coins, int amount) 
    {
        if (coins.empty()) return 0;

        int n = amount+1;
        vector<int>dp(n, INT_MAX);
        dp[0] = 0;

        for (int amount=1; amount<n; amount++) {

            for (int j=0; j<coins.size(); j++) {
                if ( coins[j] <= amount && dp[amount-coins[j]] != INT_MAX ) {
                    dp[amount] = min(dp[amount], dp[amount - coins[j]] + 1);
                }
            }
        }
        return (dp[n-1] == INT_MAX) ? -1 : dp[n-1];
    }
};