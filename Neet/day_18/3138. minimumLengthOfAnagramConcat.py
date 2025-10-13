# This approach exceeds runtime limit
from collections import Counter
class Solution:
    def minAnagramLength(self, s: str) -> int:
        for i in range(len(s)-1, -1, -1):
            currString = s[i: ]
            print("currString: ", currString)
            
            l, r = 0, len(currString)
            while r<=len(s):
                ok = True
                print(s[l:r])
                if not Solution.isAnagram(self, s[l:r], currString):
                    ok = False
                    break
                l += len(currString)
                r += len(currString)
            print("r pointer: ", r)
            if ok and len(s)%len(currString)==0:
                print("res: ", len(currString))
                return len(currString)

    def isAnagram(self, string, target):
        if len(string) != len(target):
            return False
        stringCounter = Counter(string)
        targetCounter = Counter(target)
        return stringCounter == targetCounter

def main():
    self = Solution
    # s = "abba" # output = 2
    # s = "cdef" # output = 4
    s = "abbbaa" # output = 6
    Solution.minAnagramLength(self, s)

    # print(Solution.isAnagram(self, "abbb", "babb"))
main()