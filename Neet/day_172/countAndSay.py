class Solution(object):
    def countAndSay(self, n):
        prev = "1"
        for _ in range(1, n):
            prev = self.countAndSayHelper(prev)
        return prev

    def countAndSayHelper(self, s):
        if len(s) == 0:
            return ""
        
        stack = []
        for i in range(len(s)):
            if stack and stack[-1][0] == s[i]:
                stack[-1][1] += 1
            else:
                stack.append( [s[i], 1] )

        # consolidate the stack
        res = ""
        while stack:
            num, count = stack[-1]
            stack.pop()
            foo = str(count) + num
            res = foo + res
        return res