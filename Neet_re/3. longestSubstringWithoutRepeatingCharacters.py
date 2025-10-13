class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        res = 0
        l = 0
        charSet = set()

        for r in range(len(s)):
            while s[r] in charSet:
                charSet.remove(s[l])
                l += 1
            
            charSet.add(s[r])
            res = max(res, len(charSet))
        print(res)
        return res
    
        #################### inefficient #################
        # res = 0
        # if s == "":
        #     return len(s)
        # l, r = 0, 0
        # currSet = set()

        # while r<len(s):
        #     print(r)
        #     if s[r] not in currSet:
        #         currSet.add(s[r])
        #         r += 1
        #     else:
        #         res = max(res, len(currSet))
        #         l += 1
        #         r = l
        #         currSet.clear()
        # res = max(res, len(currSet))
        # return res
                
def main():
    self = Solution
    # s = "abcabcbb"
    # s = "bbbbb"
    # s = "pwwkew"
    s = "au"
    Solution.lengthOfLongestSubstring(self, s)
main()