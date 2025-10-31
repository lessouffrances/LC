class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        dp = [ [ 0 for _ in range(len(word1)+1) ] for _ in range(len(word2)+1) ]

        for row in dp:
            print(row, end="\n")
        print("\n\n")

        for r in range(len(word2)+1):
            for c in range(len(word1)+1):
                if r == 0:
                    dp[r][c] = c
                elif c == 0:
                    dp[r][c] = r
                
                else:
                    if word1[c-1] == word2[r-1]:
                        dp[r][c] = dp[r-1][c-1]
                
                    else:
                        dp[r][c] = min(dp[r-1][c], dp[r-1][c-1], dp[r][c-1])+1
            
        
        for row in dp:
            print(row, end="\n")
        print("\n\n")
        return dp[-1][-1]
            

def main():
    solution = Solution()
    word1 = "horse"
    word2 = "ros" #3

    # word1 = "intention"
    # word2 = "execution" #5

    solution.minDistance(word1, word2)
main()