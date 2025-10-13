class Solution:
    def maximalSquare(self, matrix) -> int:
        dp = [ [int(matrix[row][col]) for col in range(len(matrix[0]))] for row in range(len(matrix)) ]

        for row in range(len(matrix)-2, -1, -1):
            for col in range(len(matrix[0])-2, -1, -1):
                the_set = set([dp[row+1][col+1], dp[row+1][col], dp[row][col+1]])
                criteria = len(the_set) 

                if int(matrix[row][col]) == 0:
                    dp[row][col] = 0
                else:
                    dp[row][col] = min(dp[row+1][col], dp[row][col+1], dp[row+1][col+1])+1
        
        for row in dp:
            print(row, end="\n")
        print("\n\n")

        print(max(max(row) for row in dp) ** 2)
        return max(max(row) for row in dp) ** 2

def main():
    solution = Solution()
    # matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]] #4
    # matrix = [["1","1","1","1","0"],["1","1","1","1","0"],["1","1","1","1","1"],["1","1","1","1","1"],["0","0","1","1","1"]] #16
    matrix = [["1","0","1","1","0","1"],["1","1","1","1","1","1"],["0","1","1","0","1","1"],["1","1","1","0","1","0"],["0","1","1","1","1","1"],["1","1","0","1","1","1"]] #4
    solution.maximalSquare(matrix)
main()
        