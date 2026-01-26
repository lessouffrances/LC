class Solution 
{
    public:
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        ROW = matrix.size();
        COL = matrix[0].size();

        int maxLen = INT_MIN;
        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (!visited.count( {r, c} )) {
                    maxLen = max(dfs(r, c, matrix), maxLen);
                    visited.clear();
                }
            }
        }

        return maxLen == INT_MIN ? -1 : maxLen;
    }
    private:
    int ROW, COL;
    set<pair<int, int>> visited;
    vector<pair<int, int>> DIRS = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    int dfs(int row, int col, vector<vector<int>>& matrix)
    {
        int pathLen = 1;
        visited.insert( {row, col} );

        for (auto& DIR : DIRS) {
            int newR = row + DIR.first;
            int newC = col + DIR.second;

            if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
            if (visited.count( {newR, newC} )) continue;
            if (matrix[newR][newC] <= matrix[row][col]) continue;

            pathLen = max(pathLen, 1+dfs(newR, newC, matrix));
            visited.erase( {newR, newC} );
        }
        return pathLen;
    }
};