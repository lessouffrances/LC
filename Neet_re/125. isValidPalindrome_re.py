class Solution:
    def isPalindrome(self, s: str) -> bool:
        res = ""
        for char in s:
            if char.isalnum():
                res += char.lower()
        return res[::-1] == res

def main():
    self = Solution()
    s = "A man, a plan, a canal: Panama"
    print(Solution.isPalindrome(self, s))
main()