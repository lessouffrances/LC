class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s = s.split(" ")
        slist = [ char for char in s if char != ""]
        return len(slist[-1])





def main():
    self = Solution
    s = "   fly me   to   the moon  "
    print(Solution.lengthOfLastWord(self, s))
main()