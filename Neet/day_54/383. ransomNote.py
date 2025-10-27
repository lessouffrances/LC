from collections import Counter
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        ransomNoteDict = dict(Counter(ransomNote))
        magazineDict = dict(Counter(magazine))

        for char, count in ransomNoteDict.items():
            if char in magazineDict and magazineDict[char] >= count:
                continue
            else:
                return False
        return True

            


        