class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        windowSet = set()
        res = 0

        l, r = 0, 0
        while r<len(s):        
            if s[r] not in windowSet:
                windowSet.add(s[r])
            else:
                res = max(res, r-l)
                l += 1
                r = l
            r += 1
        print(res)
        return res


            



def main():
    self = Solution
    s = "abcabcbb"
    # s = "bbbbb"
    # s = "pwwkew"
    Solution.lengthOfLongestSubstring(self, s)
main()