class Solution:
    def maxProfit(self, prices) -> int:
        left, right = 0 , 0
        max_proft = 0

        for right in range(len(prices)):
            profit = prices[right]-prices[left]
            
            if profit < 0:
                left = right
            
            max_proft = max(profit, max_proft)

        print(max_proft)
        return max_proft
                


        


def main():
    solution = Solution()
    prices = [7,1,5,3,6,4] #5
    solution.maxProfit(prices)
main()