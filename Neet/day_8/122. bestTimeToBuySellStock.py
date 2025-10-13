class Solution:
    def maxProfit(self, prices) -> int:
        l, r = 0, 1
        totalProfit = 0

        while r < len(prices):
        
            if prices[r] > prices[l]:
                profit = prices[r] - prices[l]
                totalProfit += profit
                l += 1
            else:
                l = r

            r += 1
        
        print(totalProfit)




def main():
    self = Solution()
    # prices = [7, 1, 5, 3, 6, 4]
    # prices = [1, 2, 3, 4, 5]
    prices = [7, 6, 4, 3, 1]
    print(Solution.maxProfit(self, prices))

main()