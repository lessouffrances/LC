class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        magazineMap, ransomNoteMap = {}, {}

        for i in range(len(magazine)):
            magazineMap[magazine[i]] = 1 + magazineMap.get(magazine[i], 0)
        
        for i in range(len(ransomNote)):
            ransomNoteMap[ransomNote[i]] = 1 + ransomNoteMap.get(ransomNote[i], 0)

        for char in magazineMap:
            if char in ransomNoteMap and ransomNoteMap[char] >= magazineMap[char]:
                continue
            return False
        return True

def main():
    self = Solution()
    ransomNote = "aab"
    magazine = "baa"
    print(Solution.canConstruct(self, ransomNote, magazine))

main()