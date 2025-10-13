class Solution:
    def numDecodings(self, s) -> int:
        if int(s[0]) == 0:
            return 0

        dp = [ 0 for _ in range(len(s)+1) ]
        dp[0] = 1
        dp[1] = 1
        print(dp)
        
        for i in range(2, len(dp)):
            print(int(s[i-2]+s[i-1]))
            if int(s[i-1]) != 0:
                dp[i] = dp[i-1]
                print("1-digit check: ", dp, end="\n")
            if int(s[i-2]) != 0 and int(s[i-2]+s[i-1]) <= 26:
                dp[i] += dp[i-2]
                print("2-digit check: ", dp, end="\n")
        return dp[-1]

 

def main():
    solution = Solution()
    # s = "226" #3
    # s = "12" #2
    s = "06" #0
    # s = "11106" #2
    solution.numDecodings(s)
main()