class Solution(object):
    def maxProfit(self, prices):
        if not prices:
            return 0
        
        n = len(prices)
        lowest = float('inf')
        max_profit = 0

        for i in range(n):
            if prices[i] < lowest:
                lowest = prices[i]
            max_profit = max(max_profit, prices[i]-lowest)
        return max_profit        