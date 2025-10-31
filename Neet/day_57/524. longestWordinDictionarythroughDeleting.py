class Solution:
    def findLongestWord(self, s, dictionary) -> str:
        def isSubsequence(s, t):
            if len(s) > len(t):
                return False
            
            i = 0
            for char in t:
                if i < len(s) and s[i] == char:
                    i += 1
            return len(s) == i
        
        dictionary.sort()
        dictionary.sort(key=len, reverse=True)

        for word in dictionary:
            if isSubsequence(word, s):
                return word

        return ""


def main():
    solution = Solution()
    s = "abpcplea"
    dictionary = ["ale","apple","monkey","plea"] # "apple"

    # s = "abpcplea"
    # dictionary = ["a","b","c"] # "a"

    solution.findLongestWord(s, dictionary)


main()
        