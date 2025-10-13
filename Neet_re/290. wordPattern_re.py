class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        pattern = list(pattern)
        s = s.split()
        if len(pattern) != len(s):
            return False
        
        charToWord, WordToChar = {}, {}

        for char, word in zip(pattern, s):
            if (char in charToWord and charToWord[char] != word):
                return False
            elif (word in WordToChar and WordToChar[word] != char):
                return False
            charToWord[char] = word
            WordToChar[word] = char
        return True

def main():
    self = Solution()
    pattern = "abba"
    s = "dog dog dog dog"
    print(Solution.wordPattern(self, pattern, s))
main()