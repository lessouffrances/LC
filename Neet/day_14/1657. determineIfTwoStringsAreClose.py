class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        if len(word1) != len(word2):
            return False
        
        hashMap1 = {}
        count1 = []
        char1 = set()
        hashMap2 = {}
        count2 = []
        char2 = set()

        for i in range(len(word1)):
            hashMap1[word1[i]] = hashMap1.get(word1[i], 0) + 1
            hashMap2[word2[i]] = hashMap2.get(word2[i], 0) + 1
        
        for key in hashMap1:
            count1.append(hashMap1[key])
            char1.add(key)
        
        for key in hashMap2:
            count2.append(hashMap2[key])
            char2.add(key)

        count1.sort()
        count2.sort()

        return True if count1 == count2 and char1 == char2 else False


def main():
    self = Solution
    # word1 = "abc"
    # word2 = "bca"
    # word1 = "cabbba"
    # word2 = "abbccc"
    # word1 = "a"
    # word2 = "aa"

    word1 = "uau"
    word2 = "ssx"
    print(Solution.closeStrings(self, word1, word2))


main()