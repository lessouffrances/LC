class Solution 
{
    public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        ROW = heights.size();
        COL = heights[0].size();

        // pacific: top and left 
        set<pair<int, int>> pacificReachables;
        for (int c=0; c<COL; c++) {
            dfs(0, c, pacificReachables, heights);
        }
        for (int r=0; r<ROW; r++) {
            dfs(r, 0, pacificReachables, heights);
        }

        // atlantic: bottom and right
        set<pair<int, int>> atlanticReachables;
        for (int c=0; c<COL; c++) {
            dfs(ROW-1, c, atlanticReachables, heights);
        }
        for (int r=0; r<ROW; r++) {
            dfs(r, COL-1, atlanticReachables, heights);
        }

        vector<vector<int>> res;
        for (auto& [r, c] : pacificReachables) {
            if (atlanticReachables.count( {r, c} )) {
                res.push_back( {r, c} );
            }
        }
        return res;
    }

    private:
    int ROW, COL;
    vector<pair<int, int>> DIRS = { {0,1}, {0,-1}, {1,0}, {-1,0} };

    void dfs(int row, int col, set<pair<int, int>>& reachables, vector<vector<int>>& heights)
    {
        reachables.insert( {row, col} );

        for (auto& DIR : DIRS) {
            int newR = row + DIR.first;
            int newC = col + DIR.second;

            if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
            if (heights[newR][newC] < heights[row][col]) continue;
            if (reachables.count( {newR, newC} )) continue;
            dfs(newR, newC, reachables, heights);
        }
    }
};