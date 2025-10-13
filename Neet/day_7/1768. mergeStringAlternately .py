
class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        length = min(len(word1), len(word2))
        word_1 = word1[:length]
        word_2 = word2[:length]
        if len(word1) <= len(word2):
            remain = word2[length:]
        elif len(word1) > len(word2):
            remain = word1[length:]
        
        res = ""

        for i in range(len(word_1)):
            res += word_1[i]
            res += word_2[i]
        
        res = res + remain
        return res

def main():
    self = Solution()
    word1 = "abcd"
    word2 = "pq"
    Solution.mergeAlternately(self, word1, word2)
main()
