class Solution:
    def coinChange(self, coins, amount) -> int:
        if amount == 0:
            return 0
        
        coins = sorted(coins, reverse=True)
        num_coin, residual = 0, amount
        
                


def main():
    solution = Solution()
    coins = [1,2,5]
    amount = 11 # 3 

    coins = [186,419,83,408]
    amount = 6249 #20
    print(solution.coinChange(coins, amount))
main()