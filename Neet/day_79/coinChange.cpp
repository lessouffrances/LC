class Solution
{
    public:
    int coinChange(vector<int>& coins, int amount) 
    {
        if (coins.size() == 0 || amount == 0) return 0;
        int n = amount + 1;
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;

        for (int currAmt=1; currAmt<=amount; currAmt++) {
            int minNumOfCoins = INT_MAX;
            for (int j=0; j<coins.size(); j++) {
                if (coins[j] <= currAmt && dp[currAmt-coins[j]] != INT_MAX) {
                    minNumOfCoins = min(minNumOfCoins, dp[currAmt-coins[j]]+1);
                }
            }
            dp[currAmt] = minNumOfCoins;
        }
        if (dp[n-1] != INT_MAX) return dp[n-1];
        return -1;
    }
};
