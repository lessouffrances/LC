class Solution(object):
    def isPalindrome(self, x):
        if x < 0:
            return False
        
        res = ""
        while x != 0:
            digit = x % 10
            res += str(digit)
            x = x // 10
        
        reverse_res = res[::-1]
        return reverse_res == res