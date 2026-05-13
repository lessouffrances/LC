class Solution:
    def getMinimumConflicts(self, primary, secondary):
        primary_less_than = self.precomputeLessThan(primary)
        secondary_less_than = self.precomputeLessThan(secondary)

        m = len(primary)
        n = len(secondary)

        # assign space
        dp = [ [ float('inf') for _ in range(n+1) ] for _ in range(m+1) ]
        dp[0][0] = 0     

        for i in range(m+1):
            for j in range(n+1):
                if dp[i][j] == float('inf'):
                    continue
                curr = dp[i][j]

                if i<m:
                    ch = ord(primary[i])-ord('a')
                    conflicts = primary_less_than[i+1][ch] + secondary_less_than[j][ch]
                    dp[i+1][j] = min(dp[i+1][j], curr+conflicts)
                
                if j<n:
                    ch = ord(secondary[j])-ord('a')
                    conflicts = primary_less_than[i][ch] + secondary_less_than[j+1][ch]
                    dp[i][j+1] = min(dp[i][j+1], curr+conflicts)
        return dp[m][n]


    def precomputeLessThan(self, s):
        n = len(s)
        # assign space:
        less_than = [ [ 0 for _ in range(26)] for _ in range(n+1) ]

        for i in range(n-1, -1, -1):
            less_than[i] = less_than[i+1][:]
            ch = ord(s[i])-ord('a')
            for k in range(ch+1, 26):
                less_than[i][k] += 1

        return less_than 

    