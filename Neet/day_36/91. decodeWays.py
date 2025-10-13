class Solution:
    def numDecodings(self, s: str) -> int:
        if int(s[0]) == 0:
            return 0

        dp = [ 0 for _ in range(len(s)+1) ]
        dp[0], dp[1] = 1, 1

        for i in range(2, len(s)+1):
            if int(s[i-1]) != 0:
                dp[i] = dp[i-1]
            if int(s[i-2]) != 0 and int(s[i-2: i]) <= 26:
                dp[i] += dp[i-2]
                
        print(dp)
        return dp[-1]

def main():
    solution = Solution()
    s = "11106" #12322
    s = "12" #12
    s = "27"
        
    solution.numDecodings(s)
main()