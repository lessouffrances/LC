class Solution:
    def shiftGrid(self, grid, k):
        flatGrid = [ _ for row in grid for _ in row]

        k = k % len(flatGrid)
        shiftGrid = flatGrid[-k: ] + flatGrid[: len(flatGrid)-k]
        print(shiftGrid)

        rows = len(grid)
        cols = len(grid[0])

        regrid = [shiftGrid[i * cols :(i + 1) * cols] for i in range(rows)]
        return regrid


def main():
    self = Solution
    grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]]
    k = 4

    Solution.shiftGrid(self, grid, k)
main()


        