







class Solution 
{
    public:
    int largestIsland(vector<vector<int>>& grid) 
    {
        if (grid.empty()) return 0;
        ROW = grid.size();
        COL = grid[0].size();

        int islandID = 2;
        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (grid[r][c] == 1) {
                    grid[r][c] = islandID;
                    int size = dfs(r, c, islandID, grid);
                    islandSizeLookup[islandID] = size;
                    islandID++;
                }
            }
        }

        int maxSize = INT_MIN;
        for (auto& [id, size] : islandSizeLookup) {
            maxSize = max(maxSize, size);
        }

        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (grid[r][c] == 0) {
                    // get the adjacent island
                    unordered_set<int> IDS = getAdjacentIslandIDs(r, c, grid);
                    int size = 1;
                    for (int id : IDS) {
                        size += islandSizeLookup[id];
                    }
                    maxSize = max(maxSize, size);
                }
            }
        }
        return maxSize;
    }
    private:
    int ROW, COL;
    unordered_map<int, int> islandSizeLookup; // { ID: size }
    vector<pair<int, int>> DIRS = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    unordered_set<int> getAdjacentIslandIDs(int row, int col, vector<vector<int>>& grid)
    {
        unordered_set<int> adjIDs;

        for (auto& DIR : DIRS) {
            int newR = row + DIR.first;
            int newC = col + DIR.second;

            if (newR<0 || newR >= ROW || newC<0 || newC>=COL) continue;  
            if (grid[newR][newC] >= 2) adjIDs.insert(grid[newR][newC]);
        }
        return adjIDs;
    }
    int dfs(int row, int col, int islandID, vector<vector<int>>& grid)
    {
        int size = 1;
        
        for (auto& DIR : DIRS) {
            int newR = row + DIR.first;
            int newC = col + DIR.second;

            if (newR<0 || newR >= ROW || newC<0 || newC>=COL) continue;
            if (grid[newR][newC] != 1) continue;
            grid[newR][newC] = islandID;
            size += dfs(newR, newC, islandID, grid);
        }
        return size;
    }
};