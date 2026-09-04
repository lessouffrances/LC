class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if len(prices) == 0: return 0

        buy = prices[0]
        max_profit = 0
        for i in range(1, len(prices)):
            max_profit = max(max_profit, max(prices[i]-buy, 0))
            buy = min(prices[i], buy)
        return max_profit