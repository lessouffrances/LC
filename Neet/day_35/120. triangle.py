class Solution:
    def minimumTotal(self, triangle) -> int:
        row_num = len(triangle)

        dp = triangle
        dp[0] = triangle[0]
        for row in dp:
            print(row, end="\n")
        print("\n\n")

        for row in range(1, row_num):
            for col in range(row+1):
                if col-1 < 0:
                    dp[row][col] += dp[row-1][col]
                elif col >= len(dp[row-1]):
                    dp[row][col] += dp[row-1][col-1]
                else:
                    dp[row][col] += min(dp[row-1][col-1], dp[row-1][col])
        
        print(min(dp[-1]))
        return min(dp[-1])

def main():
    solution = Solution()
    # triangle = [[2],[3,4],[6,5,7],[4,1,8,3]] #11
    triangle = [[-10]] #-10
    solution.minimumTotal(triangle)
main()