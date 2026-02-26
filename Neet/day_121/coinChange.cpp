




class Solution 
{
    public:
    // return the minimum number of coins to make up amount
    int coinChange(vector<int>& coins, int amount) 
    {
        if (coins.empty()) return 0;

        vector<int>dp(amount+1, INT_MAX);
        // there's 0 coin to make up 0
        dp[0] = 0;
        for (int amt=1; amt<=amount; amt++) {
            for (int coin : coins) {
                if (coin <= amt && dp[amt-coin] != INT_MAX) {
                    // 1 + dp[amt-coin] : this coin + # coins to make (amt-coin)
                    dp[amt] = min( dp[amt], 1 + dp[amt-coin] );
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};