class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        if word1 == word2:
            return 0
        elif len(word1) == 0 and len(word2) != 0:
            return len(word2)
        elif len(word2) == 0 and len(word1) != 0:
            return len(word1)

        dp = [ [0 for _ in range(len(word1)+1)] for _ in range(len(word2)+1) ] 

        for lst in dp:
            print(lst, end="\n")
        print("\n")

        for i in range(0, len(word1)+1):
            dp[0][i] = i
        for j in range(0, len(word2)+1):
            dp[j][0] = j
        
        for i in range(1, len(word2)+1):
            for j in range(1, len(word1)+1):
                if word1[j-1] == word2[i-1]:
                    dp[i][j] = dp[i-1][j-1]
                elif i == j:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
                else:
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1])+1
                
                for lst in dp:
                    print(lst, end="\n")
                print("\n")
        print(dp[-1][-1])
        return dp[-1][-1]

def main():
    solution = Solution()
    # word1 = "horse"
    # word2 = "ros" # 3

    # word1 = "intention"
    # word2 = "execution" # 5

    word1 = "sea"
    word2 = "eat"  # 2
    solution.minDistance(word1, word2)
main()