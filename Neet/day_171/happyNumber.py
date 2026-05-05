class Solution(object):
    def isHappy(self, n):
        if n == 1: 
            return True
        seen = set()

        while n not in seen and n != 1:
            seen.add(n)
            n = self.generateNext(n)

        return n == 1

    def generateNext(self, n):
        next_number = 0

        while n != 0:
            digit = n % 10
            next_number += digit * digit
            n /= 10
        return next_number