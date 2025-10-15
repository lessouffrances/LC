class Solution:
    def numSquares(self, n: int) -> int:
        if n in [0, 1]:
            return n

        dp = [ n for i in range(n+1) ]
        dp[0] = 0
        dp[1] = 1
        print(f"initial dp is {dp}")

        for i in range(2, n+1):
            j = 1
            while j*j <= i:
                dp[i] = min( dp[i], dp[i-j*j]+1 )
                j += 1
        
        print(dp)
        return dp[-1]


def main():
    solution = Solution()
    # n = 12 #3. 4+4+4
    n = 13 #2  4+9
    solution.numSquares(n)


main()