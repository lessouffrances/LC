class Solution 
{
    public:
    int change(int amount, vector<int>& coins) 
    {
        if (coins.empty()) return 0;

        vector<unsigned long long> dp(amount+1, 0);
        dp[0] = 1;

        for (int coin : coins) {
            for (int amt=1; amt<amount+1; amt++) {
                if (coin > amt) continue;
                dp[amt] += dp[amt-coin];
            }
        }
        return dp[amount];
    }
};