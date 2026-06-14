class Solution 
{
    public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        ROW = obstacleGrid.size();
        COL = obstacleGrid[0].size();
        memo.assign(ROW, vector<int>(COL, -1));

        if (obstacleGrid[0][0] == 1 || obstacleGrid[ROW-1][COL-1] == 1) return 0;
        
        return dfs(0, 0, obstacleGrid);
    }

    private:
    vector<pair<int, int>> DIRS = { {1,0}, {0,1} };
    int ROW = 0, COL = 0;
    vector<vector<int>> memo;

    int dfs(int row, int col, vector<vector<int>>& obstacleGrid)
    {
        if (row == ROW-1 && col == COL-1) return 1;
        if (memo[row][col] != -1) return memo[row][col];
        int numOfWays = 0;

        for (auto& DIR : DIRS) {
            int newR = row+DIR.first;
            int newC = col+DIR.second;

            if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
            if (obstacleGrid[newR][newC] == 1) continue;
            
            // don't have to track visited, 
            // because based on the nature fo the track,
            // there is no way that the robot will step back
            numOfWays += dfs(newR, newC, obstacleGrid) ;
        }

        memo[row][col] = numOfWays;
        return numOfWays;
    }
};