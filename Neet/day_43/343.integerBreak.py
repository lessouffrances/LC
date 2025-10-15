class Solution:
    def integerBreak(self, n: int) -> int:
        if n<=3:
            return n-1
        
        res = 1
        while n>4:
            res = res*3
            n = n-3
        return res*n



def main():
    solution = Solution()
    n = 10 #36
    n = 6 #18
    # n = 7 #12
    # n = 3 #2
    print(solution.integerBreak(n))
main()