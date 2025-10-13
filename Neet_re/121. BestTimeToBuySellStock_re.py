class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        maxP = 0
        l, r = 0, 1
        while r < len(prices):
            if prices[r] > prices[l]:
                currP = prices[r] - prices[l]
                maxP = max(currP, maxP)
            else:
                currP = 0
                l = r
            r += 1
        return maxP

def main():
    self = Solution()
    prices = [7,6,4,3,1]
    #           l       r
    Solution.maxProfit(self, prices)
main()