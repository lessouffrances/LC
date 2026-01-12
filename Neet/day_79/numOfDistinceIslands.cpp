class Solution {
    public:
    int numDistinctIslands(vector<vector<int>>& grid) 
    {
        if (grid.empty()) return -1;
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
    vector<pair<int, int>> DIRS = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    int ROW, COL;
    set<string> distinctIslands;
    void bfsAndSignature(vector<vector<int>>& grid, int row, int col)
    {
        queue<pair<int, int>> q;
        q.push( {row, col} );
        grid[row][col] = -1; // mark visited
        string encodedIsland = "";
        int level = 1;

        while (!q.empty()) {
            int size = q.size();
            encodedIsland += to_string(size + level);

            for (int i=0; i<size; i++) {
                auto [r, c] q.front();
                q.pop();
                
                for (auto& DIR : DIRS) {
                    int newR = r + DIR.first;
                    int newC = c + DIR.second;
                    if (newR<0 || newR>=ROW || newC<0 || newC >= COL) continue;
                    if (grid[newR][newC] == -1 || grid[newR][newC] == 0) continue;

                    grid[newR][newC] = -1; // mark visited
                    encodedIsland += to_string(DIR.first + DIR.second);
                    q.push( {newR, newC} );
                }
            }
            level++;
        }
        distinctIslands.insert(encodedIsland);
    }
};