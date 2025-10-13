class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        closeToOpen = {')' : '(', ']' : '[', '}' : '{'} # map close to open 

        for char in s: 
            if char in closeToOpen:
                if stack and stack[-1] == closeToOpen[char]:
                    stack.pop()
                else: 
                    return False
            else: 
                stack.append(char)

        return True if not stack else False

def main():
    self = Solution()
    s1 = '(){}[]'
    s2 = '({[]})'
    print(Solution.isValid(s1))
    print(Solution.isValid(s2))

main()