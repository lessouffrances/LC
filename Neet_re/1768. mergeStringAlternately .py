class Solution:
    def mergeAlternately(self, word1, word2):
        i, j = 0, 0
        res = ""

        while i < len(word1) and j < len(word2):
            res += word1[i]
            res += word2[j]
            i, j = i+1, j+1
        
        if i == len(word1):
            res += word2[j: ]
        if j == len(word2):
            res += word1[i: ]

        return res

def main():
    self = Solution
    word1 = "ab"
    word2 = "pqrs"
    # word1 = "abcd"
    # word2 = "pq"
    print(Solution.mergeAlternately(self, word1, word2))
main()