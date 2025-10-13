class Solution:
    def isUgly(self, n: int) -> bool:
        if n <= 0:
            return False
        for p in [2, 3, 5]:
            while n % p == 0:
                n = n // p 
            
        return n == 1
    



def main():
    self = Solution()
    n = 6
    print(Solution.isUgly(self, n))

main()

# divide the n by 2, 3, 5 as many times as we can, 
# until it reduces to 1.