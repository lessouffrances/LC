class Solution:
    def maxProfit(self, prices) -> int:
        if len(prices) == 1:
            return 0
        dp = [ [0, 0, 0] for _ in range(len(prices)+1) ]
        dp[0][0] = -prices[0]
        print(dp)
        
        for i in range(1, len(dp)):
            dp[i][0] = max(dp[i-1][0], dp[i-1][2]-prices[i-1])
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]+prices[i-1])
            dp[i][2] = dp[i-1][1]
        print(dp)
        
        return dp[-1][1]


def main():
    solution = Solution()
    prices = [1,2,3,0,2] #3
    solution.maxProfit(prices)
main()