class Solution(object):
    def findCoins(self, numWays):
        n = len(numWays)
        res = []
        
        while True:
            c = -1
            for i in range(n):
                if numWays[i] == 1:
                    c = i+1
                    break
            if c == -1: break
            res.append(c)

            old = numWays[:]
            for s in range(c, n+1):
                if s == c:
                    numWays[s-1] -= 1
                else:
                    numWays[s-1] -= old[s-c-1]
        
        for x in numWays:
            if x != 0: return []
        return res