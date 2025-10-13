class Solution:
    def minCost(self, costs) -> int:
        dp = [ [0, 0, 0] for _ in range(len(costs)) ]
        dp[0] = costs[0]

        for i in range(1, len(costs)):
            for j in range(len(costs[i])):
                temp = dp[i-1].copy()  
                temp.pop(j)
                dp[i][j] = costs[i][j] + min(temp)
        
        print(min(dp[-1]))
        print(dp)

def main():
    solution = Solution()
    costs = [[17,2,17],[16,16,5],[14,3,19]] #10
    # costs = [[7,6,2]] #2
    # costs = [[5,8,6],[19,14,13],[7,5,12],[14,15,17],[3,20,10]] #43
            # [ [5, 8, 6], [25, 19, 18], [25, 23, 31], [37, 40, 40], [43, 57, 47] ]
    solution.minCost(costs)
main()