class Solution 
{
    public:
    int largestIsland(vector<vector<int>>& grid) 
    {
        if (grid.empty()) return 0;
        ROW = grid.size();
        COL = grid[0].size();

        int isLandID = 2;
        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (grid[r][c] == 1) {
                    grid[r][c] = isLandID;
                    int size = dfs(r, c, grid, isLandID);
                    sizeLookUp[isLandID] = size;
                    isLandID++;
                }
            }
        }

        int maxSize = INT_MIN;
        for (auto& [id, size] : sizeLookUp) {
            maxSize = max(maxSize, size);
        }

        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                // the starting point is critical
                if (grid[r][c] == 0) {
                    unordered_set<int> adjIDs = getAdjIsland(r, c, grid);
                    int size = 1;
                    for (int id : adjIDs) {
                        size += sizeLookUp[id];
                    }
                    maxSize = max(maxSize, size);
                }
            }
        }
        return maxSize;
    }

    private:
    int ROW, COL;
    unordered_map<int, int> sizeLookUp; // { ID : size }
    vector<pair<int, int>> DIRS = { {0,1}, {0,-1}, {1,0}, {-1,0} };
    unordered_set<int> getAdjIsland(int row, int col, vector<vector<int>>& grid)
    {
        unordered_set<int> adjIDs;
        for (auto& DIR : DIRS) {
            int newR = row + DIR.first;
            int newC = col + DIR.second;

            if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
            if (grid[newR][newC] >= 2) {
                adjIDs.insert(grid[newR][newC]);
            }
        }
        return adjIDs;
    }
    
    int dfs(int row, int col, vector<vector<int>>& grid, int id)
    {
        int size = 1;

        for (auto& DIR : DIRS) {
            int newR = row+DIR.first;
            int newC = col+DIR.second;

            if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
            if (grid[newR][newC] != 1) continue;
            grid[newR][newC] = id;
            size += dfs(newR, newC, grid, id);
        }
        return size;
    }
};