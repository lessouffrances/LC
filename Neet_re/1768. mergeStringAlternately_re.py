class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        i, j = 0, 0
        res = []
        while i < len(word1) and j < len(word2):
            res.append(word1[i])
            res.append(word2[j])
            i += 1
            j += 1
        
        res.append(word1[i:])
        res.append(word2[j:])
        res = "".join(res)
       
        print(res)
        return res
            

def main():
    self = Solution()
    word1 = "abcd"
    word2 = "pq"
    Solution.mergeAlternately(self, word1, word2)
main()