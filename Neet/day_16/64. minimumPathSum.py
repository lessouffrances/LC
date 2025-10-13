class Solution:
    def minPathSum(self, grid) -> int:
        m, n = len(grid), len(grid[0])

        for i in range(m-1, -1, -1):
            for j in range(n-1, -1, -1):
                if (i+1) <= (m-1) and (j+1) <= (n-1):
                    grid[i][j] += min(grid[i+1][j], grid[i][j+1])
                if (i+1) > (m-1) and (j+1) <= (n-1):
                    grid[i][j] += grid[i][j+1]
                if (i+1) <= (m-1) and (j+1) > (n-1):
                    grid[i][j] += grid[i+1][j]

        return grid[0][0]
        
def main():
    self = Solution
    grid = [[1,3,1],[1,5,1],[4,2,1]]
    Solution.minPathSum(self, grid)
main()