class Solution(object):
    def generate(self, numRows):
        if numRows == 1: return [ [1] ]

        dp = [ [] for _ in range(1, numRows+1) ]

        for row in range(numRows):
            dp[row] = [1] * (row+1)
            for col in range(1, row):
                dp[row][col] = dp[row-1][col-1]+dp[row-1][col]
        return dp

        