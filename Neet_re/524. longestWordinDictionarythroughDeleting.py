class Solution:
    def findLongestWord(self, s: str, dictionary) -> str:
        candidates = []
        for word in dictionary:
            if Solution.isSubsequence(self, word, s):
                candidates.append(word)
        print(candidates)

        hashMap = {}
        for word in candidates:
            if len(word) in hashMap:
                hashMap[len(word)].append(word)
            else:
                hashMap[len(word)] = [word]
        print(hashMap)

        if hashMap:
            longestLength = sorted(hashMap.keys(), reverse=True)[0]
            finalRoundCandidates = hashMap[longestLength]
            return sorted(finalRoundCandidates)[0]
        return ""

    def isSubsequence(self, string, target):
        if len(string)>len(target):
            return False
        i = 0
        for char in target:
            if i<len(string) and string[i] == char:
                i += 1
        return i == len(string)

    

def main():
    self = Solution
    s = "abpcplea"
    dictionary = ["ale","apple","monkey","plea"]  # output = "apple"
    s = "apple"
    dictionary = ["xjsdhj", "hskia"] # output = ""
    print(Solution.findLongestWord(self, s, dictionary))
main()