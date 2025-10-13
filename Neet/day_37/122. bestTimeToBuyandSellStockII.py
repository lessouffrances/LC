class Solution:
    def maxProfit(self, prices) -> int:
        left, right = 0, 0
        
        max_profit = 0
        for right in range(len(prices)):
            profit = prices[right]-prices[left]
            if profit > 0:
                max_profit += profit
                left = right
            else:
                left = right
        print(max_profit)
        return max_profit

    
def main():
    solution = Solution()
    prices = [7,1,5,3,6,4] #7
    prices = [1,2,3,4,5] #4

    solution.maxProfit(prices)
main()