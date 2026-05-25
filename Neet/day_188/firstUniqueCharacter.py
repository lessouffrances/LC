class Solution(object):
    def firstUniqChar(self, s):
        if not s: return -1

        for i, ch in enumerate(s):
            if s.count(ch) == 1:
                return i
        
        return -1