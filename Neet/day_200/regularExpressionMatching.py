class Solution(object):
    def isMatch(self, s, p):
        COL = len(p)+1
        ROW = len(s)+1

        dp = [ [ False for _ in range(COL) ] for _ in range(ROW) ]
        dp[0][0] = True
        dp[0][1] = True if p[0] == '.' or p[0] == '*' else False

        # fill the first row
        for c in range(2, COL):
            if p[c-1] == '*':
                dp[0][c] = dp[0][c-2]


        for r in range(1, ROW):
            for c in range(1, COL):
                # the char is a match
                if p[c-1] == s[r-1] or p[c-1] == '.':
                    dp[r][c] = dp[r-1][c-1]
                    continue

                if p[c-1] == '*':
                    dp[r][c] = dp[r][c-2]

                    if p[c-2] == s[r-1] or p[c-2] == '.':
                        dp[r][c] = dp[r][c] or dp[r-1][c]

        return dp[ROW-1][COL-1] 
