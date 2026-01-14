class Solution {
    public:
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        if (grid.empty()) return 0;

        ROW = grid.size();
        COL = grid[0].size();
        int maxArea = 0;

        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (grid[r][c] == 1) {
                    grid[r][c] = 2;
                    maxArea = max(dfsOneIsland(r, c, grid), maxArea);
                }
            }
        }
        return maxArea;
    }

    private:
    int ROW, COL;
    vector<pair<int, int>> DIRS = {{0,1},{0,-1},{1,0},{-1,0}};
    int dfsOneIsland(int row, int col, vector<vector<int>>& grid)
    {
        int currArea = 1;

        for (auto& DIR : DIRS) {
            int newR = row + DIR.first;
            int newC = col + DIR.second;

            if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
            if (grid[newR][newC] == 2 || grid[newR][newC] == 0) continue; // check visited
            if (grid[newR][newC] == 1) {
                grid[newR][newC] = 2; // mark visited
                currArea += dfsOneIsland(newR, newC, grid);
            }
        }

        return currArea;
    }
};