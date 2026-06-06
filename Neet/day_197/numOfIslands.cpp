class Solution 
{
    public:
    int numIslands(vector<vector<char>>& grid) 
    {
        if (grid.empty()) return 0;
        ROW = grid.size();
        COL = grid[0].size();

        int res = 0;
        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (grid[r][c] == '1') {
                    dfs(r, c, grid);
                    res++;
                }
            }
        }
        return res;
    }

    private:
    int ROW = 0;
    int COL = 0;
    vector<pair<int, int>> DIRS = {{0,1}, {0,-1}, {-1,0}, {1,0}};
    void dfs(int r, int c, vector<vector<char>>& grid)
    {
        grid[r][c] = '#'; // mark as visited

        for (auto& DIR : DIRS) {
            int newR = r+DIR.first;
            int newC = c+DIR.second;

            if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
            if (grid[newR][newC] != '1') continue;
            dfs(newR, newC, grid);
        }
    }
};