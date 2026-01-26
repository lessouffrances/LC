class Solution 
{
    public:
    int largestIsland(vector<vector<int>>& grid) 
    {
        if (grid.empty()) return 0;
        ROW = grid.size();
        COL = grid[0].size();

        unordered_map<int, int> lookUp; // { id, size }
        int ID = 2;
        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (grid[r][c] == 1) {
                    lookUp[ID] = dfs(r, c, grid, ID);
                    ID++;
                }
            }
        }

        int maxSize = INT_MIN;
        // maxSize before any flippings
        for (auto& [id, size] : lookUp) {
            maxSize = max(maxSize, size);
        }

        // simulate the flipping
        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (grid[r][c] == 0) {
                    unordered_set<int> adjIslandIDs = getAllAdjacentIslandsByIDs(r, c, grid);
                    int size = 1;
                    for (auto& islandID : adjIslandIDs) {
                        size += lookUp[islandID];
                    }
                    maxSize = max(maxSize, size);
                }
            }
        }

        return maxSize;
    }

    private:
    int ROW, COL;
    vector<pair<int, int>> DIRS = {{0,1},{0,-1},{1,0},{-1,0}};
    // get all adjacent islandIds
    unordered_set<int> getAllAdjacentIslandsByIDs(int row, int col, vector<vector<int>>& grid)
    {
        if (row<0 || row>=ROW || col<0 || col>= COL) return {};

        unordered_set<int> res;
        for (auto& DIR : DIRS) {
            int newR = row + DIR.first;
            int newC = col + DIR.second;

            if (newR>=0 && newR<ROW && newC>=0 && newC<COL && grid[newR][newC] > 1) {
                res.insert(grid[newR][newC]);
            }
        }
        return res;
    }

    // return the size of the island and mark the island
    int dfs(int row, int col, vector<vector<int>>& grid, int islandID) 
    {
        int size = 1;
        grid[row][col] = islandID;
        
        for (auto& DIR : DIRS) {
            int newR = row + DIR.first;
            int newC = col + DIR.second;

            if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
            if (grid[newR][newC] != 1) continue;
            size += dfs(newR, newC, grid, islandID);
        }

        return size;
    }
};