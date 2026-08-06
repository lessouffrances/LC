class Solution 
{
    public:
    int numDistinctIslands(vector<vector<int>>& grid) 
    {
        if (grid.empty()) return 0;

        ROW = grid.size();
        COL = grid[0].size();

        set<string> distinctIslands;
        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (visited.count( {r, c} )) continue;
                if (grid[r][c] != 1) continue;
                string currPath = "";
                dfs(r, c, currPath, grid);
                distinctIslands.insert(currPath);
            }
        }
        return distinctIslands.size();
    }

    private:
    int ROW, COL;
    set<pair<int, int>> visited;
    vector<pair<int, int>> DIRS = { {0,1}, {0,-1}, {1,0}, {-1,0} };
    vector<char> DIRSCHAR = { 'R', 'L', 'D', 'U' }; // right, left, down, up

    void dfs(int row, int col, string& currPath, vector<vector<int>>& grid)
    {
        visited.insert( {row, col} );

        for (int i=0; i<DIRS.size(); i++) {
            int newR = row+DIRS[i].first;
            int newC = col+DIRS[i].second;

            if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
            if (visited.count( {newR, newC} )) continue;
            if (grid[newR][newC] != 1) continue;

            currPath += DIRSCHAR[i];
            visited.insert( {newR, newC} );
            dfs(newR, newC, currPath, grid);
            currPath += "B";
        }
    }
};