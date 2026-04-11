






class Solution 
{
    public:
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        ROW = matrix.size();
        COL = matrix[0].size();
        
        int maxPath = -1;
        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                maxPath = max(maxPath, dfs(r, c, matrix));
            }
        }
        return maxPath;
    }
    private:
    unordered_map<int, int> memo;
    vector<pair<int, int>> DIRS = { {0,1}, {0,-1}, {1,0}, {-1,0} };
    int ROW, COL;

    int dfs(int row, int col, vector<vector<int>>& matrix)
    {
        int key = row*COL + col;
        if (memo.count(key)) return memo[key];

        int pathLen = 1;
        for (auto& DIR : DIRS) {
            int newR = row + DIR.first;
            int newC = col + DIR.second;

            if (newR<0 || newC<0 || newR>=ROW || newC>=COL) continue;
            if (matrix[newR][newC] <= matrix[row][col]) continue;

            pathLen = max(pathLen, 1 + dfs(newR, newC, matrix));
        }

        memo[key] = pathLen;
        return pathLen;
    }
};