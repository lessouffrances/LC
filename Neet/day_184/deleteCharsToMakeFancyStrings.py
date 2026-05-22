class Solution(object):
    def makeFancyString(self, s):
        if not s:
            return ""
        n = len(s)
        count = 1
        res = s[0]

        for i in range(1, n):
            if s[i] == s[i-1]:
                count += 1
            else:
                count = 1
            if count >= 3: continue
            res += s[i]
        return res
        