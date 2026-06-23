
// Q1: in order to get to bottom-right, which dirs can the robot go?
// A1: right and bottom

// Q2: if the obstacles on either starting point or end point?
// A2: return 0

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
    int ROW = 0, COL = 0; 
    vector<vector<int>> memo;
    vector<pair<int, int>> DIRS = { {1,0}, {0,1} };
    int dfs(int row, int col, vector<vector<int>>& obstacleGrid)
    {
        if (row == ROW-1 && col == COL-1) return 1;
        if (memo[row][col] != -1) return memo[row][col];
        int numWays = 0;

        for (auto& DIR : DIRS) {
            int newR = row+DIR.first;
            int newC = col+DIR.second;
            if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
            if (obstacleGrid[newR][newC] == 1) continue;

            numWays += dfs(newR, newC, obstacleGrid);
        } 
        memo[row][col] = numWays;
        return numWays;
    }
};