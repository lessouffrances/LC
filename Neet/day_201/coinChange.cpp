class Solution 
{
    public:
    int coinChange(vector<int>& coins, int amount) 
    {
        if (coins.empty()) return 0;
        vector<int> dp(amount+1, INT_MAX);
        // base case
        dp[0] = 0;

        for (int amt=1; amt<=amount; amt++) {
            for (int i=0; i<coins.size(); i++) {
                if (coins[i] <= amt && dp[amt-coins[i]] != INT_MAX) {
                    dp[amt] = min(dp[amt], 1+dp[amt-coins[i]]);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};