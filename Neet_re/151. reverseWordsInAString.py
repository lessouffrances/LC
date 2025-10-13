class Solution:
    def reverseWords(self, s: str) -> str:
        sList = s.split()
        sList = sList[::-1]
        return " ".join(sList)
        



def main():
    self = Solution
    s = "the sky is blue"
    s = "a good   example"
    print(Solution.reverseWords(self, s))
main()
