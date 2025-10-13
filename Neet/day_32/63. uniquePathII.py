class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid) -> int:
        if not obstacleGrid:
            return 0

        m = len(obstacleGrid[0])+1 #col
        n = len(obstacleGrid)+1 #row
        print(f"The width is {m} and the height is {n}")

        extraBottom = [ 0 for _ in range(m) ]
        obstacleGrid.append(extraBottom)

        for i in range(n-1):
            obstacleGrid[i].append(0)

        obstacleGrid[n-2][m-1] = 1

        for row in range(n-2, -1, -1):
            for col in range(m-2, -1, -1):
                if obstacleGrid[row][col] == 1:
                    obstacleGrid[row][col] = 0
                else:
                    obstacleGrid[row][col] = obstacleGrid[row+1][col] + obstacleGrid[row][col+1]
        for row in obstacleGrid:
            print(row, end='\n')
        print('\n\n')
        return obstacleGrid[0][0]


def main():
    solution = Solution()
    obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]] #2
    obstacleGrid = [[0,1],[0,0]] #1
    print(solution.uniquePathsWithObstacles(obstacleGrid))
main()