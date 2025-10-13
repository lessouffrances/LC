class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        n = len(s1)
        for i in range(len(s2)):
            currString = s2[i: i+n]
            if Solution.isPerm(self, currString, s1):
                return True
        return False
    
    def isPerm(self, string, target):
        if len(string) != len(target):
            return False
        
        stringMetric = [0] * 26
        targetMetric = [0] * 26

        for sChar, tChar in zip(string, target):
            stringMetric[ord(sChar)-ord("a")] += 1
            targetMetric[ord(tChar)-ord("a")] += 1
            
        return stringMetric == targetMetric

def main():
    self = Solution
    s1 = "ab"
    s2 = "eidbaooo"
    # True

    # s1 = "ab"
    # s2 = "eidboaoo"
    # False

    print(Solution.checkInclusion(self, s1, s2))
    # print(Solution.isPerm(self, "abca", "bcaa"))
main()
