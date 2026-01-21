class Solution 
{
    public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int ROW = obstacleGrid.size();
        int COL = obstacleGrid[0].size();

        // if the start or end is blocked
        if (obstacleGrid[0][0] == 1 || obstacleGrid[ROW-1][COL-1] == 1) return 0;

        // if not returned yet, bottom-right corner is 1
        obstacleGrid[ROW-1][COL-1] = 1;

        // fill the bottom row and right col 
        for (int r=ROW-2; r>=0; r--) {
            if (obstacleGrid[r][COL-1] == 1) {
                obstacleGrid[r][COL-1] = 0;
                continue;
            }
            obstacleGrid[r][COL-1] = obstacleGrid[r+1][COL-1];
        }  
        for (int c=COL-2; c>=0; c--) {
            if (obstacleGrid[ROW-1][c] == 1) {
                obstacleGrid[ROW-1][c] = 0;
                continue;
            }
            obstacleGrid[ROW-1][c] = obstacleGrid[ROW-1][c+1];
        }   

        for (int r=ROW-2; r>=0; r--) {
            for (int c=COL-2; c>=0; c--) {
                if (obstacleGrid[r][c] == 1) {
                    obstacleGrid[r][c] = 0;
                    continue;
                }

                long long val = ((long long)obstacleGrid[r+1][c] + (long long)obstacleGrid[r][c+1]);
                obstacleGrid[r][c] = (int) val;
            }
        }

        return obstacleGrid[0][0];
    }
};