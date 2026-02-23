




class Solution 
{
    public:
    int coinChange(vector<int>& coins, int amount) 
    {
        // contains the fewest num of coins to make up that amount
        vector<int>dp(amount+1, INT_MAX);
        // base case, 0 coins make up 0
        dp[0] = 0; 

        for (int amt=1; amt<=amount; amt++) {
            for (int coin : coins) {
                if (coin<=amt && dp[amt-coin] != INT_MAX) {
                    dp[amt] = min( 1+dp[amt-coin], dp[amt] );
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};