class Solution 
{
    public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        if (grid.empty()) return 0;
        ROW = grid.size();
        COL = grid[0].size();
        memo.assign(ROW, vector<int>(COL, -1));
        return dfs(0, 0, grid);
    }
    private:
    int ROW, COL;
    vector<pair<int, int>> DIRS = { {1,0},{0,1} };
    vector<vector<int>> memo; // the minPathSum to this pos

    int dfs(int row, int col, vector<vector<int>>& grid)
    {
        // base case
        if (row == ROW-1 && col == COL-1) 
        return grid[ROW-1][COL-1];

        if (memo[row][col] != -1) return memo[row][col];

        int minPathSum = INT_MAX;

        // recurse
        for (auto& DIR : DIRS) {
            int newR = row + DIR.first;
            int newC = col + DIR.second;

            if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
            minPathSum = min(minPathSum, grid[row][col] + dfs(newR, newC, grid));
        }
        memo[row][col] = minPathSum;
        return minPathSum;
    }
};