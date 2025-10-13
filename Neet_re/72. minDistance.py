class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        cache = [ [float("inf")] * (len(word1)+1) for i in range(len(word2)+1) ]
        cache[len(word2)][len(word1)] = 0

        for i in range(len(word1), -1, -1):
            cache[len(word2)][i] = len(word1)-i
        for j in range(len(word2), -1, -1):
            cache[j][len(word1)] = len(word2)-j
        
        print(cache)

        for j in range(len(word2)-1, -1, -1):
            for i in range(len(word1)-1, -1, -1):
                if word1[i] == word2[j]:
                    cache[j][i] = cache[j+1][i+1]
                else:
                    cache[j][i] = 1+min( cache[j+1][i], cache[j][i+1], cache[j+1][i+1] )

        return cache[0][0]

def main():
    self = Solution
    word1 = "horse"
    word2 = "ros"
    print(Solution.minDistance(self, word1, word2))


main()