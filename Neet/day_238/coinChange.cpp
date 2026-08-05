class Solution 
{
    public:
    int coinChange(vector<int>& coins, int amount) 
    {
        if (coins.empty()) return 0;

        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;

        for (int amt=1; amt<=amount; amt++) {
            for (int coin : coins) {
                if (amt-coin>=0 && dp[amt-coin] != INT_MAX) {
                    dp[amt] = min(dp[amt], dp[amt-coin]+1);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};