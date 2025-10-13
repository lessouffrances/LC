from collections import Counter

class Solution:
    def findAnagrams(self, s: str, p: str):
        pMap = dict(Counter(p))
        res = []

        for i in range(len(s)-len(p)+1):
            window = s[i: i+len(p)]
            print(window)
            sMap = dict(Counter(window))
            if sMap == pMap:
                res.append(i)
                print(res)
        return res

def main():
    solution = Solution()
    s = "cbaebabacd"
    p = "abc"

    # s = "abab"
    # p = "ab"
    solution.findAnagrams(s, p)
main()