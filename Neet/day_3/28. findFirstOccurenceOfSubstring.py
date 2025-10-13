class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if len(needle) == 0 or len(haystack) == 0:
            return 0
        
        if needle in haystack:
            return haystack.index(needle)
        return -1

def main():
    self = Solution()
    haystack = "jujsad"
    needle = "sad"
    print(Solution.strStr(self, haystack, needle))
main()