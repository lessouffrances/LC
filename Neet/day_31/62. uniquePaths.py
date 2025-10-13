class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [ [0 for _ in range(n+1)] for _ in range(m+1) ]
        for row in dp:
            print(row, end="\n")
        print("\n\n")
        
        dp[m][n-1] = 1
        for row in dp:
            print(row, end="\n")
        print("\n\n")

        for row in range(m-1, -1, -1):
            for col in range(n-1, -1, -1):
                print(row, col)
                dp[row][col] = dp[row+1][col] + dp[row][col+1]
        
        for row in dp:
            print(row, end="\n")
        print("\n\n")

        return dp[0][0]
    

def main():
    solution = Solution()
    m = 3
    n = 7 #28
    solution.uniquePaths(m, n)
main()