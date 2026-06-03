# This one looks like a sliding window, 
# but somehow, it cannot be solved by sliding window

class Solution(object):
    def countVowelSubstrings(self, word):
        if not word:
            return 0
        
        vowels = set("aeiou")
        count = 0

        for start in range(len(word)):
            seen = set()
            for char in word[start: ]:
                if char not in vowels: break
                seen.add(char)
                if len(seen) == 5:
                    count += 1
        return count