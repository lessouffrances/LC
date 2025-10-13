class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s = s.split()
        print(s) 
        word = s[-1]
        print(len(word))
        return len(word)


def main():
    self = Solution()
    s = "   fly me   to   the moon  "
    Solution.lengthOfLastWord(self, s)

main()