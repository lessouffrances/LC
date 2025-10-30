class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        # allocate dp with extra row and col
        dp = [ [0 for _ in range(len(text1)+1)] for _ in range(len(text2)+1) ]
        for row in dp:
            print(row, end="\n")
        print("\n\n")

        for r in range(1, len(text2)+1):
            for c in range(1, len(text1)+1):
                # if two elements equal
                if text2[r-1] == text1[c-1]:
                    dp[r][c] = dp[r-1][c-1] + 1
                else:
                    dp[r][c] = max( dp[r-1][c], dp[r][c-1] )
        
        for row in dp:
            print(row, end="\n")
        print("\n\n")

        return dp[-1][-1]









def main():
    solution = Solution()
    text1 = "abcde"
    text2 = "ace" 
    solution.longestCommonSubsequence(text1, text2)
    # a b c d e
    # a c e
main()