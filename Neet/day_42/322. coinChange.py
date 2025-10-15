class Solution:
    def coinChange(self, coins, amount) -> int:
        if amount == 0:
            return 0

        dp = [ [0] * (amount+1) for _ in range(len(coins)+1) ]
        for i in range(len(coins)-1, -1, -1):
            for j in range(1, amount+1):
                dp[i][j] = float('inf')
                take = float('inf')
                noTake = float('inf')

                if j-coins[i]>=0:
                    take = dp[i][j-coins[i]]
                    if take != float('inf'):
                        take += 1

                if i+1 < len(coins):
                    noTake = dp[i+1][j]

                dp[i][j] = min(take, noTake)
        
        if dp[0][amount] != float('inf'):
            return dp[0][amount]
        return -1
        
def main():
    solution = Solution()
    coins = [1,2,5]
    amount = 11 # 3 

    coins = [186,419,83,408]
    amount = 6249 #20
    print(solution.coinChange(coins, amount))
main()