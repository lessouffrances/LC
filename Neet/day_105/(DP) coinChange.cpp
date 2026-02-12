





class Solution 
{
    public:
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;

        for (int currAmount=1; currAmount<=amount; currAmount++) {
            for (int j=0; j<coins.size(); j++) {
                if (coins[j] <= currAmount && dp[currAmount-coins[j]] != INT_MAX) {
                    dp[currAmount] = min(dp[currAmount], 1 + dp[currAmount-coins[j]]);
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};