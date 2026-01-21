class Solution 
{
    public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        if (heights.empty()) return {};
        ROW = heights.size();
        COL = heights[0].size();

        set<pair<int, int>> pacific;
        // top row: pacific
        for (int c=0; c<COL; c++) {
            pacific.insert( {0, c});
            dfs(0, c, heights, pacific);
        }

        // left col: pacific
        for (int r=0; r<ROW; r++) {
            pacific.insert( {r, 0});
            dfs(r, 0, heights, pacific);
        }

        set<pair<int, int>> atlantic;
        // bottom row: atlantic
        for (int c=0; c<COL; c++) {
            atlantic.insert( {ROW-1, c});
            dfs(ROW-1, c, heights, atlantic);
        }

        // right col: atlantic
        for (int r=0; r<ROW; r++) {
            atlantic.insert( {r, COL-1});
            dfs(r, COL-1, heights, atlantic);
        }

        // check for overlap
        vector<vector<int>> res;
        for (auto& [r, c] : pacific) {
            if (atlantic.count({r, c})) {
                res.push_back({r, c});
            }
        }
        return res;
    }

    private:
    int ROW, COL;
    vector<pair<int, int>> DIRS = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    void dfs(int row, int col, vector<vector<int>>& heights, set<pair<int, int>>& reachables)
    {
        reachables.insert({row, col});

        for (auto& DIR : DIRS) {
            int newR = row+DIR.first;
            int newC = col+DIR.second;

            if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
            if (reachables.count({newR, newC})) continue;
            if (heights[newR][newC] < heights[row][col]) continue;

            dfs(newR, newC, heights, reachables);
        }
    }
};