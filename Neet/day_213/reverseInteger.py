class Solution(object):
    def reverse(self, x):
        sign = -1 if x < 0 else 1
        x = abs(x)

        res = 0
        while x:
            digit = x % 10
            x //= 10
            res = res * 10 + digit
        res = sign * res
        if res < -2**31 or res > 2**31-1: return 0
        return res
        