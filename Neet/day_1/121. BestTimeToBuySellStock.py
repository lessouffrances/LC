class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        l, r = 0, 1 # two starting pointers
        maxP = 0
        while r < len(prices):
            if prices[r] > prices[l]:
                profit = prices[r] - prices[l]
                maxP = max(profit, maxP)
            else:
                l = r
            r += 1
        print(maxP)
        return maxP
            

def main():
    prices = [7, 1, 5, 3, 6, 4]    # output = 5
    # prices = [7, 6, 4, 3, 1]
    self = Solution()
    Solution.maxProfit(self, prices)

main()
        