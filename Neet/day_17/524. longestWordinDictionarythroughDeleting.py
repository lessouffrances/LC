class Solution:
    def findLongestWord(self, s: str, dictionary) -> str:
        candidates = []
        for word in dictionary:
            if Solution.isSubsequence(self, word, s):
                candidates.append(word)
        
        candidates.sort(key=len, reverse=True)
        hashMap = {}

        # { 3: "abe", "abc" }
        for candidate in candidates:
            if len(candidate) in hashMap:
                hashMap[len(candidate)].append(candidate)
            else:
                hashMap[len(candidate)] = [candidate]

        choices = next(iter(hashMap.values()), [])
        if choices:
            choices.sort()
            return choices[0]
        return ""

        
    def isSubsequence(self, s, t):
        if len(s) > len(t):
            return False
        i = 0
        for char in t:
            if i < len(s) and s[i] == char:
                i += 1
        return i == len(s)

def main():
    self = Solution
    # s = "abpcplea"
    # dictionary = ["ale","apple","monkey","plea"] # "apple"
    # s = "abpcplea"
    # dictionary = ["a","b","c"] # "a"
    s = "abce"
    dictionary = ["abe","abc"] # 'abc'
    print(Solution.findLongestWord(self, s, dictionary))
main()