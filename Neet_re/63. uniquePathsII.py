class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid) :  
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        resGrid = [ [float("inf")] * n for i in range(m) ]

        # if either top-left or bottom-right is 1, return 0
        if obstacleGrid[0][0] == 1 or obstacleGrid[m-1][n-1] == 1:
            return 0
        
        if obstacleGrid[m-1][n-1] == 0:
            resGrid[m-1][n-1] = 1
        
        # right col
        for i in range(m-2, -1, -1):
            if obstacleGrid[i][n-1] == 0:
                resGrid[i][n-1] = resGrid[i+1][n-1]
            else:
                resGrid[i][n-1] = 0
        
        # bottom row
        for j in range(n-2, -1, -1):
            if obstacleGrid[m-1][j] == 0:
                resGrid[m-1][j] = resGrid[m-1][j+1]
            else:
                resGrid[m-1][j] = 0
        
        for i in range(m-2, -1, -1):
            for j in range(n-2, -1, -1):
                if obstacleGrid[i][j] == 0:
                    resGrid[i][j] = resGrid[i+1][j] + resGrid[i][j+1]
                else:
                    resGrid[i][j] = 0
        
        return resGrid[0][0]



        print(resGrid)


        

        

def main():
    self = Solution
    obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
    Solution.uniquePathsWithObstacles(self, obstacleGrid)
main()
        