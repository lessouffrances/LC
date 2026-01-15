class Solution {
    public:
    int numDistinctIslands(vector<vector<int>>& grid) 
    {
        if (grid.empty()) return 0;
        ROW = grid.size();
        COL = grid[0].size();

        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (grid[r][c] == 1) {
                    bfsAndSignature(grid, r, c);
                }
            }
        }

        return distinctIslands.size();
    }
    private:
    int ROW, COL;
    vector<pair<int, int>> DIRS = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    set<set<pair<int, int>>> distinctIslands;
    void bfsAndSignature(vector<vector<int>>& grid, int row, int col)
    {
        if (grid.empty()) return;
        queue<pair<int, int>> q;
        q.push( {row, col} );
        grid[row][col] = -1;
        set<pair<int, int>> signature; // to record the pos relative to the source

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            signature.insert( {r-row, c-col} );

            for (auto& DIR : DIRS) {
                int newR = r + DIR.first;
                int newC = c + DIR.second;
                
                if (newR<0 || newR >= ROW || newC<0 || newC>=COL) continue;
                if (grid[newR][newC] == -1 || grid[newR][newC] == 0) continue;

                grid[newR][newC] = -1;
                q.push( {newR, newC} );
            }
        }

        distinctIslands.insert(signature);
    }
};