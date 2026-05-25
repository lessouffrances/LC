class Solution(object):
    def reverseString(self, s):
        if not s:
            return s
        
        n = len(s)
        for i in range(n/2):
            temp = s[i]
            s[i] = s[n-i-1]
            s[n-i-1] = temp
        return s
        