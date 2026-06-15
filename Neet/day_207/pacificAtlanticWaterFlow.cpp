class Solution 
{
    public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        ROW = heights.size();
        COL = heights[0].size();

        set<pair<int, int>> pacific; // topRow and leftCol
        set<pair<int, int>> atlantic; // bottomRow and rightCol
        for (int c=0; c<COL; c++) {
            dfs(0, c, heights, pacific);
            dfs(ROW-1, c, heights, atlantic);
        }

        for (int r=0; r<ROW; r++) {
            dfs(r, 0, heights, pacific);
            dfs(r, COL-1, heights, atlantic);
        }

        // see overlap
        vector<vector<int>> res;
        for (auto& coordinates : pacific) {
            if (atlantic.count(coordinates)) {
                res.push_back( {coordinates.first, coordinates.second} );
            }
        }
        return res;
    }

    private:
    vector<pair<int, int>> DIRS = { {0,1}, {0,-1}, {1,0}, {-1,0} };
    int ROW, COL;

    void dfs(int row, int col, vector<vector<int>>& heights, set<pair<int, int>>& reachables)
    {
        reachables.insert( {row, col} );

        for (auto& DIR : DIRS) {
            int newR = row + DIR.first;
            int newC = col + DIR.second;

            if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
            if (reachables.count( {newR, newC} )) continue;
            if (heights[newR][newC] < heights[row][col]) continue;

            dfs(newR, newC, heights, reachables);
        }
    }
};
