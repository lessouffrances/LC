
// T: O(ROW * COL)
// S: O(ROW * COL)
class Solution 
{
    public:
    bool containsCycle(vector<vector<char>>& grid) 
    {
        ROW = grid.size();
        COL = grid[0].size();

        // FULL dfs
        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (visited.count( {r, c} )) continue;        
                ancestorStack.clear();     
                if (dfs(r, c, -1, -1, grid[r][c], grid)) return true;
            }
        }
        return false;
    }

    private:
    // do traverse for a path that's full of val.
    // if the ancestorStack got hit,
    // return true
    int ROW = 0, COL = 0;
    set<pair<int, int>> ancestorStack;
    set<pair<int, int>> visited;
    vector<pair<int, int>> DIRS = { {0,1}, {0,-1}, {1,0}, {-1,0} };
    bool dfs(int row, int col, int prevRow, int prevCol, char val, vector<vector<char>>& grid)
    {
        ancestorStack.insert( {row, col} );
        visited.insert( {row, col} );

        for (auto& DIR : DIRS) {
            int newR = row + DIR.first;
            int newC = col + DIR.second;
            if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
            if (newR == prevRow && newC == prevCol) continue;  // don't go back to parent
            if (ancestorStack.count( {newR, newC} )) return true;
            if (visited.count( {newR, newC} )) continue;
            if (grid[newR][newC] != val) continue;
            if (dfs(newR, newC, row, col, val, grid)) return true;
        }
        ancestorStack.erase( {row, col} );
        return false;
    }
};