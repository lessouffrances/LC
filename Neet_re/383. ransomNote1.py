from collections import Counter
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        ransomNoteMap = {}
        magazineMap = {}

        for char in ransomNote:
            ransomNoteMap[char] = ransomNote.count(char)
        for char in magazine:
            magazineMap[char] = magazine.count(char)
        
        print(ransomNoteMap)
        print(magazineMap)

        for key in ransomNoteMap:
            if key not in magazineMap or magazineMap[key] < ransomNoteMap[key]:
                return False
        return True

        # ransomNoteCounter = Counter(ransomNote)
        # magazineCounter = Counter(magazine)

        # for key, value in ransomNoteCounter.items():
        #     if key not in magazineCounter or magazineCounter[key] < value:
        #         return False
        # return True
    
def main():
    self = Solution
    # ransomNote = "a"
    # magazine = "b" # false

    # ransomNote = "aa" 
    # magazine = "ab" # false

    ransomNote = "aa"
    magazine = "aab" # true
    
    print(Solution.canConstruct(self, ransomNote, magazine))
main()