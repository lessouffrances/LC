class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        charSet = set()
        l = 0
        res = 0

        for r in range(len(s)):
            while s[r] in charSet:
                charSet.remove(s[l])
                l += 1
            charSet.add(s[r])
            res = max(res, r-l+1)
        
        return res   
        

def main():
    self = Solution()
    s = "abcabcbb"
    print(Solution.lengthOfLongestSubstring(self, s))

main()