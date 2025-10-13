class Solution:
    def maxProfit(self, prices) -> int:
        l, r = 0, 1
        maxProfit = 0

        while r < len(prices):
            diff = prices[r]-prices[l]
            if diff > 0:
                currProfit = diff
                maxProfit = max(currProfit, maxProfit)

            else:
                l = r
            r += 1

        return maxProfit



def main():
    self = Solution
    prices = [7,1,5,3,6,4]
    print(Solution.maxProfit(self, prices))
main()

        
