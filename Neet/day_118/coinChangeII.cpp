



class Solution 
{
    public:
    int change(int amount, vector<int>& coins) 
    {
        // contains how many ways to make up the amount
        vector<unsigned long long> dp(amount+1, 0);
        dp[0] = 1;

        for (int coin: coins) {
            for (int amt=coin; amt<=amount; amt++) {
                dp[amt] += dp[amt - coin];
            }
        }

        return dp[amount];
    }
};