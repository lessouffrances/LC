class Solution:
    def reverseWords(self, s: str) -> str:
        s = s.split()
        s = s[::-1]
        str = " ".join(s)
        print(str)
        return str

def main():
    # s = "a good   example"
    s = "  hello world  "
    self = Solution()
    Solution.reverseWords(self, s)
main()