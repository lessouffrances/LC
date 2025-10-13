class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        magazineMap, ransomNoteMap = {}, {}

        for i in range(len(magazine)):
            magazineMap[magazine[i]] = magazine.count(magazine[i])

        for i in range(len(ransomNote)):
            ransomNoteMap[ransomNote[i]] = ransomNote.count(ransomNote[i])

        for key in ransomNote:
            if key in magazineMap and magazineMap[key] >= ransomNoteMap[key]:
                continue
            return False
        return True

def main():
    self = Solution()
    ransomNote = "aab"
    magazine = "baa"
    print(Solution.canConstruct(self, ransomNote, magazine))

main()