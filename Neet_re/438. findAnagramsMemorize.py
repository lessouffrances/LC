## Through this practice I print out the actual anagram string in each window
from collections import Counter
class Solution:
    def findAnagrams(self, s: str, p: str):
        pMap = Counter(p)
        windowMap = Counter()
        k = len(p)
        res = []

        for i in range(len(s)):
            windowMap[s[i]] += 1
            if i>=k:
                if windowMap[s[i-k]] == 1:
                    del windowMap[s[i-k]]
                else:
                    windowMap[s[i-k]] -= 1
            if windowMap == pMap:
                res.append(s[i-k+1: i+1])
        print(res)
        return res  


def main():
    self = Solution
    s = "cbaebabacd"
    p = "abc"
    Solution.findAnagrams(self, s, p)
main()