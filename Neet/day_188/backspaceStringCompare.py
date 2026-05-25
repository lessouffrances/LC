class Solution(object):
    def backspaceCompare(self, s, t):
        return self.processString(s) == self.processString(t)
    
    def processString(self, s):
        stack = []
        for ch in s:
            if ch == '#':
                if stack: stack.pop()
            else:
                stack.append(ch)
        return str(stack)
        
