from collections import Counter

class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        ransomNoteMap = dict(Counter(ransomNote))
        magazineMap = dict(Counter(magazine))

        for char in ransomNoteMap:
            if char not in magazineMap:
                return False
            elif char in magazineMap and magazineMap[char] < ransomNoteMap[char]:
                return False
        return True
        

def main():
    solution = Solution()
    ransomNote = "a"
    magazine = "b"

    ransomNote = "aa"
    magazine = "ab"

    ransomNote = "aa"
    magazine = "aab"

    print(solution.canConstruct(ransomNote, magazine))
main()