class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [ [0 for _ in range(n)] for _ in range(m) ]
    
        for r in range(m):
            dp[r][-1] = 1
            for c in range(n):
                if r == m-1:
                    dp[m-1][c] = 1
    
        
        for r in range(m-2, -1, -1):
            for c in range(n-2, -1, -1):
                print(r, c)
                dp[r][c] = dp[r+1][c] + dp[r][c+1]
            
        return dp[0][0]


def main():
    solution = Solution()
    m = 3
    n = 7 #28

    # m = 3
    # n = 2 #3
    solution.uniquePaths(m, n)
main()