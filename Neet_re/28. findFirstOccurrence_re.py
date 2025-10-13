class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if len(haystack) == 0 or len(needle) == 0:
            return -1
        if needle in haystack:
            index = haystack.index(needle)
            return index
        if needle not in haystack:
            return -1



def main():
    self = Solution()
    haystack = "leetcode"
    needle = "leeto"
    print(Solution.strStr(self, haystack, needle))
main()