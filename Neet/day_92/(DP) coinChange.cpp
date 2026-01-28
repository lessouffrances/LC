class Solution
{
    public:
    int coinChange(vector<int>& coins, int amount) 
    {
        if (coins.empty() || amount == 0) return 0;

        int n = amount + 1;
        int m = coins.size();
        vector<int> dp(n, INT_MAX);

        dp[0] = 0;

        for (int currAmount=1; currAmount<=amount; currAmount++) {
            int minNumOfCoins = INT_MAX;
            for (int j=0; j<m; j++) {
                if (coins[j] <= currAmount && dp[currAmount-coins[j]] != INT_MAX) {
                    minNumOfCoins = min(minNumOfCoins, 1 + dp[currAmount-coins[j]]);
                }
            }
            dp[currAmount] = minNumOfCoins;
        }

        return (dp[n-1] != INT_MAX) ? dp[n-1] : -1;
    }
};