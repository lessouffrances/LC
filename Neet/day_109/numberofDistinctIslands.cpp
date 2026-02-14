class Solution 
{
    public:
    int numDistinctIslands(vector<vector<int>>& grid) 
    {
        if (grid.empty()) return 0;
        ROW = grid.size();
        COL = grid[0].size();

        pair<int, int> srcPoint;
        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (grid[r][c] == 1) {
                    srcPoint = {r, c};
                    grid[r][c] = 2;
                    signature.clear();
                    dfs(r, c, grid, srcPoint);
                    distinctSignatures.insert(signature);
                }
            }
        }
        return distinctSignatures.size();
    }
    private:
    int ROW, COL;
    vector<pair<int, int>> DIRS = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    set<pair<int, int>> signature;
    set<set<pair<int, int>>> distinctSignatures;
    void dfs(int row, int col, vector<vector<int>>& grid, pair<int, int>& srcPoint)
    {
        for (auto& DIR : DIRS) {
            int newR = row + DIR.first;
            int newC = col + DIR.second;

            if (newR<0 || newR >= ROW || newC<0 || newC>=COL) continue;
            if (grid[newR][newC] != 1) continue;

            grid[newR][newC] = 2;
            signature.insert( {newR-srcPoint.first, newC-srcPoint.second} );
            dfs(newR, newC, grid, srcPoint);
        }
    }
};