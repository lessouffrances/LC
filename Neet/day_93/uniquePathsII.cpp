class Solution 
{
    public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        if (obstacleGrid.empty()) return 0;
        
        ROW = obstacleGrid.size();
        COL = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[ROW-1][COL-1] == 1) return 0;

        vector<vector<int>> memo(ROW, vector<int>(COL, -1));
        return dfs(0, 0, obstacleGrid, memo);
    }
    private:
    int ROW, COL;
    vector<pair<int, int>> DIRS = {{0,1}, {1,0}};
    int dfs(int row, int col, vector<vector<int>>& obstacleGrid, vector<vector<int>>& memo)
    {
        int numOfUniquePaths = 0;

        if (row == ROW-1 && col == COL-1) {
            return 1;
        }

        if (memo[row][col] != -1) return memo[row][col];

        for (auto& DIR : DIRS) {
            int newR = row + DIR.first;
            int newC = col + DIR.second;

            if (newR<0 || newR >= ROW || newC<0 || newC>=COL) continue;
            if (obstacleGrid[newR][newC] != 0) continue;

            numOfUniquePaths += dfs(newR, newC, obstacleGrid, memo);
        }

        memo[row][col] = numOfUniquePaths;
        return numOfUniquePaths;
    }
};