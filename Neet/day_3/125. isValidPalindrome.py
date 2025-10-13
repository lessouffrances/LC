class Solution:
    def isPalindrome(self, s: str) -> bool:
        s_list = list(s)

        for i in range(len(s_list)):
            s_list[i] = s_list[i].strip(".,:;#@?! ").lower()
        
        s = "".join(s_list)
        s_list = list(s)
        
        stack = []
        for i in range(len(s_list) - 1, -1, -1):
            stack.append(s_list[i])

        if stack == s_list:
            return True
        return False
        
        # newStr = ""
        # for c in s:
        #     if c.isalnum(): 
        #         newStr += c.lower()
        # return newStr == newStr[::-1]
    

def main():
    self = Solution()
    s = "A man, a plan, a canal: Panama"
    # s = "ab@a"
    # s = "123454321"
    # mid = 8/2 -1 = 3
    print(Solution.isPalindrome(self, s))
    




main()