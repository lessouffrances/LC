class Solution:
    def decodeString(self, s: str) -> str:
        if len(s) == 0:
            return ""

        i = 0
        stack = [] 
        while i < len(s):
            # take out the numbers as a whole and push to stack
            if s[i].isdigit():
                curr_number = 0
                while s[i].isdigit():
                    curr_number = curr_number*10 + int(s[i])
                    i += 1
                stack.append(curr_number)

            # ], exit stack
            elif s[i] == ']':
                curr_str = []
                while stack[-1].isalpha():
                    curr_str.append(stack.pop())
                stack.pop() # pop the [
                curr_number = stack.pop()
                curr_str = "".join(curr_str[::-1])
                stack.append(curr_number * curr_str)
                i += 1

            # if letters or [, just push
            else:
                stack.append(s[i])
                i += 1

        return "".join(stack)







