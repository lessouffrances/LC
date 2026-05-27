class Solution(object):
    def compactString(self, s):

        if not s:
            return ""
        
        stack = [] # [char, count]
        n = len(s)
        for i in range(n):
            if stack and s[i] == stack[-1][0]:
                stack[-1][1] += 1
            else:
                stack.append( [s[i], 1] )
        print(stack)

        # consoliate the stack
        res = ""
        for ch, count in stack:
            if count > 1:
                res += ch + str(count)
            else:
                res += ch
        print(res)
        return res

def main():
    sol = Solution()
    s = "aaaccbbv" # "a3c2b2v"
    sol.compactString(s)

main()
