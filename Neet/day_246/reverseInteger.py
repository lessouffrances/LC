class Solution(object):
    def reverse(self, x):
        if x == 0: return x
        sign = 1 if x > 0 else -1
        x = abs(x)

        res = 0
        while x:
            digit = x % 10
            res = res * 10 + digit
            x /= 10
        
        if sign*res < -2**31 or sign*res > 2**31: return 0
        return sign*res