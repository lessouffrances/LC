
// T: O(ROW * COL)
// S: O(ROW * COL)
// use DFS: fundamental traversal method
// two sets of coords, find the intersection
class Solution 
{
    public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        ROW = heights.size();
        COL = heights[0].size();

        // happened from the edge
        // pacific edge: top and left
        set<pair<int, int>> pacific;
        set<pair<int, int>> atlantic;

        for (int c=0; c<COL; c++) {
            // top row
            dfs(0, c, pacific, heights);
            // bottom row
            dfs(ROW-1, c, atlantic, heights);
        }

        for (int r=0; r<ROW; r++) {
            // left col
            dfs(r, 0, pacific, heights);
            // right col
            dfs(r, COL-1, atlantic, heights);
        }

        // find the intersection
        vector<vector<int>> res;
        for (auto& [r, c] : atlantic) {
            if (pacific.count( {r, c} )) {
                res.push_back( {r, c} );
            }
        }
        return res;
    }
    private:
    vector<pair<int, int>> DIRS = { {0, 1}, {0,-1}, {1,0}, {-1,0} };
    int ROW = 0, COL = 0;

    void dfs(int row, int col, set<pair<int, int>>& reachables, vector<vector<int>>& heights)
    {
        reachables.insert( {row, col} );

        for (auto& DIR : DIRS) {
            int newR = row + DIR.first;
            int newC = col + DIR.second;
            if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
            if (reachables.count( {newR, newC} )) continue;
            if (heights[newR][newC] < heights[row][col]) continue;

            dfs(newR, newC, reachables, heights);
        }
    }
};