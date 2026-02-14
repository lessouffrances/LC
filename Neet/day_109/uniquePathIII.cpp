class Solution 
{
    public:
    int uniquePathsIII(vector<vector<int>>& grid) 
    {
        if (grid.empty()) return 0;

        ROW = grid.size();
        COL = grid[0].size();

        int startRow, startCol;
        int endRow, endCol;
        int numOfEmptyCells = 0;
        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (grid[r][c] == 1) {
                    startRow = r;
                    startCol = c;
                } else if (grid[r][c] == 0) {
                    numOfEmptyCells++;
                } else if (grid[r][c] == 2) {
                    endRow = r;
                    endCol = c;
                }
            }
        }

        grid[startRow][startCol] = -1;
        return dfs(startRow, startCol, numOfEmptyCells, grid, endRow, endCol);
    }
    private:
    int ROW, COL;
    vector<pair<int, int>> DIRS = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    int dfs(int row, int col, int remaining, vector<vector<int>>& grid, int endRow, int endCol)
    {

        if (row == endRow && col == endCol) {
            return remaining == 0 ? 1 : 0;
        }

        int numOfWays = 0;
        for (auto& DIR : DIRS) {
            int newR = row + DIR.first;
            int newC = col + DIR.second;

            if (newR<0 || newR >= ROW || newC<0 || newC>=COL) continue;
            if (grid[newR][newC] == -1) continue;

            int newRemaining = grid[newR][newC] == 0 ? remaining-1 : remaining;
            int original = grid[newR][newC];
            grid[newR][newC] = -1; // visited
            numOfWays += dfs(newR, newC, newRemaining, grid, endRow, endCol);

            grid[newR][newC] = original; // backtrack
        }
        return numOfWays;
    }
};