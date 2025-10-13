class Solution:
    def reverseWords(self, s: str) -> str:
        s = s.split()
        thisList = s[::-1]
        res = " ".join(thisList)
        print(res)
        return res
    
def main():
    # s = "a good   example"
    s = "  hello world  "
    self = Solution()
    Solution.reverseWords(self, s)
main()