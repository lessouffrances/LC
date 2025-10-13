from collections import Counter

class Solution:
    def isSecondHalfAnagram(self, s):
        if not s or (len(s) % 2 != 0):
            return 0
        mid = len(s)//2

        firstHalf = s[ : mid]
        secondHalf = s[mid : ]

        print("The first half is: ", firstHalf)
        print("The second half is: ", secondHalf)

        firstMap = dict(Counter(firstHalf))
        secondMap = dict(Counter(secondHalf))
        print("The first map is: ", firstMap)
        print("The second map is: ", secondMap)

        res = 0
        for char in secondMap:
            opsNeeded = abs(firstMap.get(char, 0) - secondMap[char])
            res += opsNeeded
        return res

def main():
    solution = Solution()
    s = '123456' #3
    # s = '786678' #0
    # s = '123212' #1
    print(solution.isSecondHalfAnagram(s))
main()