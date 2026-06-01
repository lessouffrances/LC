class Solution(object):
    def countVowelSubstrings(self, word):
        if not word:
            return 0
        
        vowels = {'a', 'e', 'i', 'o', 'u'}
        count = 0

        for start in range(len(word)):
            seen_vowels = set()
            for char in word[start : ]:
                if char not in vowels: break
                seen_vowels.add(char)
                if len(seen_vowels) == 5:
                    count += 1
        return count




        