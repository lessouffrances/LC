


class Solution 
{
    public:
    int numDistinctIslands(vector<vector<int>>& grid) 
    {
        if (grid.empty()) return 0;
        ROW = grid.size();
        COL = grid[0].size();

        // FULL-DFS
        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (grid[r][c] == 1) {
                    shape.clear();
                    dfs(r, c, r, c, grid);
                    distinctIslands.insert(shape);
                }
            }
        }
        return distinctIslands.size();
    }
    private:
    int ROW, COL;
    // local to each dfs call:
    set<pair<int, int>> shape; // { row-initRow, col-initCol }
    set<set<pair<int, int>>> distinctIslands;
    vector<pair<int, int>> DIRS = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    void dfs(int initRow, int initCol, 
        int row, int col, vector<vector<int>>& grid)
    {
        for (auto& DIR : DIRS) {
            int newR = row + DIR.first;
            int newC = col + DIR.second;

            if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
            if (grid[newR][newC] != 1) continue;

            grid[newR][newC] = 2; // mark as visited;
            shape.insert( {newR-initRow, newC-initCol} );
            dfs(initRow, initCol, newR, newC, grid);
        }
    }
};
        