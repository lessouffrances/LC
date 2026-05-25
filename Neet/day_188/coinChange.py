class Solution(object):
    def coinChange(self, coins, amount):
        if not coins:
            return 0
        
        dp = [-1] * (amount+1)
        dp[0] = 0
        coins.sort(reverse=True)

        for i in range(amount+1):
            min_num_of_coins = float('inf')
            for j in range(len(coins)):
                if i - coins[j] >= 0 and dp[i - coins[j]] != -1:
                    min_num_of_coins = min(min_num_of_coins, dp[i-coins[j]])
            if min_num_of_coins != float('inf'):
                dp[i] = 1 + min_num_of_coins
        
        return dp[amount]



        