class Solution:
    def shiftGrid(self, grid, k: int):
        m = len(grid) 
        n = len(grid[0])
        k = k % (m * n)

        flatedGrid = [ num for row in grid for num in row] 
        print(flatedGrid)

        shiftedFlatedGrid = flatedGrid[-k:] + flatedGrid[:-k]
        print(shiftedFlatedGrid)
        index = 0

        while index < m*n:
            for i in range(m):
                for j in range(n):
                    grid[i][j] = shiftedFlatedGrid[index]
                    index += 1
        
        print(grid)
        return grid


def main():
    self = Solution
    grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]]
    k = 4
    Solution.shiftGrid(self, grid, k)
main()