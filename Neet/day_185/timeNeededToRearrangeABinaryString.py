class Solution(object):
    def secondsToRemoveOccurrences(self, s):
        if not s:
            return 0
        
        res = 0
        zerosCount = 0

        for i in range(len(s)):
            if s[i] == '0':
                zerosCount += 1
            elif zerosCount > 0:
                res = max(res+1, zerosCount)
        return res