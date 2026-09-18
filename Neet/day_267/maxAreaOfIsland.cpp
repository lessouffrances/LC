class Solution 
{
    public:
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        if (grid.empty()) return 0;
        ROW = grid.size();
        COL = grid[0].size();

        int maxSize = 0;
        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (grid[r][c] == 1) {
                    maxSize = max(dfs(r, c, grid), maxSize);
                }
            }
        }
        return maxSize;
    }

    private:
    int ROW, COL;
    vector<pair<int, int>> DIRS = { {0,1}, {0,-1}, {1,0}, {-1,0} };
    int dfs(int row, int col, vector<vector<int>>& grid)
    {
        int size = 1;
        grid[row][col] = 2; // visited

        for (auto& DIR : DIRS) {
            int newR = row + DIR.first;
            int newC = col + DIR.second;

            if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
            if (grid[newR][newC] != 1) continue;
            // recurse
            size += dfs(newR, newC, grid);
        }
        return size;
    }
};