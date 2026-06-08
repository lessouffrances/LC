class Solution(object):
    def isMatch(self, s, p):
        ROW = len(s)+1
        COL = len(p)+1

        dp = [ [ False for _ in range(COL) ] for _ in range(ROW) ]
        dp[0][0] = True

        # fill the first row
        for c in range(1, COL):
            if p[c-1] == '*':
                dp[0][c] = dp[0][c-1]
        
        for r in range(1, ROW):
            for c in range(1, COL):
                # this char is a match
                if p[c-1] == s[r-1] or p[c-1] == '?':
                    dp[r][c] = dp[r-1][c-1]
                    continue

                if p[c-1] == '*':
                    dp[r][c] = dp[r-1][c] or dp[r][c-1]
        
        return dp[ROW-1][COL-1]

