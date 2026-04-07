class Solution 
{
public:
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        int ROW = grid.size();
        int COL = grid[0].size();

        for (int r = 0; r < ROW; r++) {
            for (int c = 0; c < COL; c++) {
                if (grid[r][c] == 1) {
                    return dfs(r, c, grid, ROW, COL);
                }
            }
        }
        return 0;
    }

private:
    vector<pair<int,int>> DIRS = {{0,1},{0,-1},{1,0},{-1,0}};

    int dfs(int row, int col, vector<vector<int>>& grid, int ROW, int COL) 
    {
        // out of bounds or water: this side is a perimeter edge
        if (row < 0 || col < 0 || row >= ROW || col >= COL) return 1;
        if (grid[row][col] == 0) return 1;
        // already visited
        if (grid[row][col] == 2) return 0;

        grid[row][col] = 2;

        int p = 0;
        for (auto& DIR : DIRS) {
            p += dfs(row + DIR.first, col + DIR.second, grid, ROW, COL);
        }
        return p;
    }
};