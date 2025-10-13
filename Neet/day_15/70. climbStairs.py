class Solution:
    def climbStairs(self, n: int) -> int:
        one, two = 1, 1

        for i in range(n-1):
            temp = one
            one = one + two
            two = temp

        return one

        
def main():
    self = Solution
    n = 2
    n = 3
    n = 5   

    print(Solution.climbStairs(self, n))

main()