class Solution:
    def validPalindrome(self, s: str) -> bool:
        if s == s[::-1]:
            return True

        for i in range(len(s)):
            rest = s[: i] + s[i+1: ]
            print(rest)
            if rest == rest[::-1]:
                return True
        return False

def main():
    solution = Solution()
    s = "aba" #true
    s = "abca" #true
    s = "abc" #false
    solution.validPalindrome(s)
main()