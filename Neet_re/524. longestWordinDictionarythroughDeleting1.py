class Solution:
    def findLongestWord(self, s: str, dictionary) -> str:
        dictionary = sorted(dictionary, key=len, reverse=True)
        candidates = []

        for word in dictionary:
            if Solution.isSubsequence(self, word, s):
                candidates.append(word)
        print("candidates: ", candidates, end="\n\n")

        hashMap = {}
        for candidate in candidates:
            if len(candidate) in hashMap:
                hashMap[len(candidate)].append(candidate)
            else:
                hashMap[len(candidate)] = [candidate]
        print("hashMap: ", hashMap, end="\n\n")
        hashMap = sorted(hashMap.items(), reverse=True)
        print(hashMap)
        if hashMap:
            finalList = sorted(hashMap[0][1])
            print(finalList)
            return finalList[0]
        else:
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
    dictionary = ["ale","apple","monkey","plea"]

    # s = "abpcplea"
    # dictionary = ["a","b","c"]
    Solution.findLongestWord(self, s, dictionary)
main()
    


