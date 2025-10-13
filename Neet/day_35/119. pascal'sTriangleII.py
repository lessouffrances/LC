class Solution:
    def getRow(self, rowIndex: int):
        dp = [ [] for _ in range(rowIndex+1) ]

        dp[0] = [1]
        for row in dp:
            print(row, end="\n")
        print("\n\n")

        for row in range(1, rowIndex+1):
            for col in range(row+1):
                if col-1 < 0 or col >= len(dp[row-1]):
                    dp[row].append(1)
                else:
                    dp[row].append(dp[row-1][col-1]+dp[row-1][col])
        print(dp[rowIndex])
        return dp[rowIndex]

def main():
    solution = Solution()
    # rowIndex = 3 # output = [1, 3, 3, 1]
    rowIndex = 0 # output = [1]
    solution.getRow(rowIndex)
main()