class Solution 
{
    public:
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        ROW = grid.size();
        COL = grid[0].size();

        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (grid[r][c] == 1) return dfs(r, c, grid);
            }
        }
        return -1;
    }

    private:
    int ROW, COL;
    vector<pair<int,int>> DIRS = {{0,1},{0,-1},{1,0},{-1,0}};

    int dfs(int row, int col, vector<vector<int>>& grid) 
    {
        if (row<0 || col<0 || row>=ROW || col>=COL) return 1;
        if (grid[row][col] == 0) return 1;
        if (grid[row][col] == 2) return 0;

        grid[row][col] = 2;

        int perimeters = 0;
        for (auto& DIR : DIRS) {
            int newR = row + DIR.first;
            int newC = col + DIR.second;

            perimeters += dfs(newR, newC, grid);
        }
        return perimeters;
    }
};