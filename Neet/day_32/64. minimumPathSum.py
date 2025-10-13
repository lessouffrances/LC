class Solution:
    def minPathSum(self, grid) -> int:
        m = len(grid) #row
        n = len(grid[0]) #col

        # base cases:
        for i in range(n):
            if i == 0:
                continue
            grid[0][i] = grid[0][i]+grid[0][i-1]
        
        for i in range(m):
            if i == 0:
                continue
            grid[i][0] = grid[i][0]+grid[i-1][0]
        
        for row in grid:
            print(row, end='\n')
        print('\n\n')

        for row in range(1, m):
            for col in range(1, n):
                grid[row][col] = grid[row][col]+min(grid[row-1][col], grid[row][col-1])
        
        for row in grid:
            print(row, end='\n')
        print('\n\n')
        return grid[-1][-1]



def main():
    solution = Solution()
    # grid = [[1,3,1],[1,5,1],[4,2,1]] #7
    grid = [[1,2,3],[4,5,6]] #12
    print(solution.minPathSum(grid))
main()