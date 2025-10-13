class Solution:
    def longestPalindrome(self, s: str) -> str:
        if s == "" or len(s) == 1:
            return s
        
        dp = [[ False for i in range(len(s))] for j in range(len(s)) ]

        for i in range(len(s)):
            for j in range(i, len(s)):
                curr = s[i: j+1]
                if curr == curr[::-1]:
                    dp[i][j] = True

        res = []
        for i in range(len(s)):
            for j in range(len(s)-1, -1, -1):
                if dp[i][j] == True:
                    res.append((i, j))
                    break

        diffRes = [ res[i][1] - res[i][0] for i in range(len(res)) ]
        index = diffRes.index(max(diffRes))
        return s[res[index][0]: res[index][1]+1]

def main():
    self = Solution
    s = "babad"
    s2 = "cbbd"
    Solution.longestPalindrome(self, s)




main()
        