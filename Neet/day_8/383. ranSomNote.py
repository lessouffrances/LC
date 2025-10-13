class Solution:
     def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        countR, countM = {}, {}
        for i in range(len(ransomNote)):
            countR[ransomNote[i]] = 1 + countR.get(ransomNote[i], 0)
        # print(countR)

        for j in range(len(magazine)):
            countM[magazine[j]] = 1 + countM.get(magazine[j], 0)
        # print(countM)

        for char in countR:
            if char in countM and countM[char] >= countR[char]:
                continue
            else:
                return False
        return True 
    
def main():
    self = Solution()
    ransomNote = "fihjjjjei"
    magazine = "hjibagacbhadfaefdjaeaebgi"
    Solution.canConstruct(self, ransomNote, magazine)
main()