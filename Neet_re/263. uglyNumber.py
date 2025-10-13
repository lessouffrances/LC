class Solution:
    def isUgly(self, n: int) -> bool:
        if n <= 0:
            return False
        for factor in [2, 3, 5]:
            while n % factor == 0:
                n = n // factor
        return n == 1

def main():
    self = Solution
    n = 6
    n = 14

    Solution.isUgly(self, n)

main()