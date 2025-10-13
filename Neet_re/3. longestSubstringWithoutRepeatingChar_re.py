class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l, r = 0, 0
        res = 0

        charSet = set()
        while r < len(s):
            if s[r] in charSet:
                charSet.remove(s[l])
                l += 1

            charSet.add(s[r])
            res = max(res, r - l + 1)
            r += 1
        print(res)
        return res

def main():
    self = Solution()
    s = "abcabcbb" # 3
    # s = "bbbbb"
    Solution.lengthOfLongestSubstring(self, s)

main()
