class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        ransomNoteMap = {}
        magazineMap = {}

        for key in ransomNote:
            ransomNoteMap[key] = ransomNote.count(key)
        for key in magazine:
            magazineMap[key] = magazine.count(key)
        
        for key in ransomNoteMap:
            if key in magazineMap and magazineMap[key] >= ransomNoteMap[key]:
                continue
            return False
        return True



def main():
    self = Solution
    ransomNote = "baa"
    magazine = "aab"
    ransomNote = "bg"
    magazine = "efjbdfbdgfjhhaiigfhbaejahgfbbgbjagbddfgdiaigdadhcfcj"
    print(Solution.canConstruct(self, ransomNote, magazine))
main()