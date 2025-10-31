class Solution:
    def longestPalindrome(self, s: str) -> str:
        if len(s) == 0 or not s:
            return ""

        res_length = 0
        res = ""

        def checkForPalindrome(l, r):
            nonlocal res_length, res
            # index in-bound and left equals to right:
            while l >= 0 and r < len(s) and s[l] == s[r]:
                if r-l+1 > res_length:
                    res_length = r-l+1
                    res = s[l: r+1]
                l, r = l-1, r+1
        
        for i in range(len(s)):
            checkForPalindrome(i, i)
            checkForPalindrome(i, i+1)
        return res
        

def main():
    solution = Solution()
    s = "babad" #"bab"
    s = "cbbd" #"bb"
    # s = "hanah" #"hanah"
    print(solution.longestPalindrome(s))
main()