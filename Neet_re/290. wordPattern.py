class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        pattern = list(pattern)
        s = s.split()

        # omg, excellent step back then
        if len(pattern) != len(s):
            return False 
        
        charToWord, wordToChar = {}, {}

        for char, word in zip(pattern, s):
            if (char in charToWord and charToWord[char] != word):
                return False
            elif (word in wordToChar and wordToChar[word] != char):
                return False
            charToWord[char] = word
            wordToChar[word] = char
        return True
        




def main():
    self = Solution
    pattern = "abba"
    s = "dog cat cat dog"
    Solution.wordPattern(self, pattern, s)
main()