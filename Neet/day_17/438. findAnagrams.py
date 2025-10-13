from collections import Counter

class Solution:
    def findAnagrams(self, s: str, p: str):
        res = []
        pHashMap = Counter(p)
        currHashMap = Counter()
        k = len(p)
        l = 0
        r = l+k

        while r <= len(s):
            currString = s[l: r]
            currHashMap = Counter(currString)
            print(currHashMap)
            if currHashMap == pHashMap:
                res.append(l)
            currHashMap.clear()
            l += 1
            r = l+k
        print(res)
        return res



def main():
    self = Solution
    s = "cbaebabacd"
    p = "abc"
    Solution.findAnagrams(self, s, p)
main()