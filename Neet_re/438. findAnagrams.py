## This approach is correct, but too slow!

from collections import Counter
class Solution:
    def findAnagrams(self, s: str, p: str):
        res = []
        k = len(p)

        for i in range(len(s)):
            if (i+k) <= len(s) and Solution.isAnagram(self, s[i: i+k], p):
                print(s[i: i+k])
                res.append(i)
        return res

    def isAnagram(self, string, target):
        if len(string) != len(target):
            return False
        
        stringMap = Counter(string)
        targetMap = Counter(target)

        for key in stringMap:
            if key in targetMap and stringMap[key] == targetMap[key]:
                continue
            else:
                return False
        return True

def main():
    self = Solution
    s = "cbaebabacd"
    p = "abc"

    Solution.findAnagrams(self, s, p)
    # print(Solution.isAnagram(self, "aeb", "abc"))
main()
        

            

        

        
