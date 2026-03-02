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
                    // reset path
                    path = "";
                    dfs(r, c, 's', grid);
                    distinctIslands.insert(path);
                }
            }
        }
        return distinctIslands.size();
    }
    private:
    int ROW, COL;
    unordered_set<string> distinctIslands;
    vector<pair<int, int>> DIRS = { {1,0},{-1,0},{0,1},{0,-1} };
    vector<char> DIRCHARS = {'D', 'U', 'R', 'L'};
    // local to each dfs call
    string path; 

    void dfs(int row, int col, char dir, vector<vector<int>>& grid)
    {
        grid[row][col] = 2; // mark as visited
        path += dir;

        for (int i=0; i<4; i++) {
            int newR = row + DIRS[i].first;
            int newC = col + DIRS[i].second;

            if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
            if (grid[newR][newC] != 1) continue;

            path += DIRCHARS[i];
            dfs(newR, newC, DIRCHARS[i], grid);
            path += 'b'; 
        }
    }
};