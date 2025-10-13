class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        k = len(s1)

        for i in range(len(s2)):
            currStr = s2[i: i+k]
            print(currStr)
            if Solution.isPerm(self, currStr, s1):
                return True
        return False

    def isPerm(self, string, target):
        if len(string) != len(target):
            return False
        
        stringMetrics = [0] * 26
        targetMetrics = [0] * 26

        for char1, char2 in zip(string, target):
            stringMetrics[ord(char1)-ord('a')] += 1
            targetMetrics[ord(char2)-ord('a')] += 1

        return stringMetrics == targetMetrics

        
        

        

def main():
    self = Solution
    # s1 = "ab"
    # s2 = "eidbaooo"

    s1 = "ab"
    s2 = "eidboaoo"

    print(Solution.checkInclusion(self, s1, s2))
    # Solution.isPerm(self, "abc", "cba")
main()