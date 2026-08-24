class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        if len(coins) == 0: return 0

        # dp setup and base cases
        dp = [float('inf')] * (amount+1)
        dp[0] = 0

        for amt in range(1, amount+1):
            for coin in coins:
                if amt-coin >= 0 and dp[amt-coin] != float('inf'):
                    dp[amt] = min(dp[amt-coin]+1, dp[amt])
        
        return dp[amount] if dp[amount] != float('inf') else -1