class Solution(object):
    def uniquePaths(self, m, n):
        # assign space
        dp = [ [ 0 for _ in range(n) ] for _ in range(m) ]

        # fill the first row and last col to be 1s
        for c in range(n):
            dp[0][c] = 1
        for r in range(m):
            dp[r][0] = 1

        for r in range(1, m):
            for c in range(1, n):
                dp[r][c] = dp[r-1][c] + dp[r][c-1]
        return dp[m-1][n-1]
        