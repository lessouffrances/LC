class Solution:
    def longestPalindrome(self, s):
        def is_palindrome_simple(s):
            return s == s[::-1]

        def findPreviousCompatible(n):
            for i in range(0, n):
                print("Now checking: ", s[i : n])
                if is_palindrome_simple(s[i : n]):
                    return s[i : n]
        if not s:
            return ""

        elif is_palindrome_simple(s):
            return s

        dp = [ 0 for i in range(len(s)+1)]
        dp[1] = s[0]

        for i in range(2, len(dp)):
            print(f"The previous longest palindrome including {s[i-1]} is: ", findPreviousCompatible(i))
            if len(dp[i-1]) >= len(findPreviousCompatible(i)):
                dp[i] = dp[i-1]
            else:
                dp[i] = findPreviousCompatible(i)
            print(dp, end="\n\n")
        
        return dp[-1]

def main():
    solution = Solution()
    s = "cbbdbba"
    s = "babad"
    s = "cbbd"
    s = "ccd" #cc
    solution.longestPalindrome(s)
main()