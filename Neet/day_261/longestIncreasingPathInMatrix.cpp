class Solution 
{
    public:
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        ROW = matrix.size();
        COL = matrix[0].size();

        int maxLen = 0;
        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                maxLen = max(maxLen, dfs(r, c, matrix));
            }
        }
        return maxLen;
    }

    private:
    int ROW, COL;
    map<pair<int, int>, int> memo;
    vector<pair<int, int>> DIRS = { {0,1}, {0,-1}, {1,0}, {-1,0} };
    int dfs(int row, int col, vector<vector<int>>& matrix)
    {
        if (memo.count( {row, col} )) return memo[ {row, col} ];

        int len = 1;
        for (auto& DIR : DIRS) {
            int newR = row + DIR.first;
            int newC = col + DIR.second;

            if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
            if (matrix[newR][newC] <= matrix[row][col]) continue;
            len = max(len, 1+dfs(newR, newC, matrix));
        }
        memo[ {row, col} ] = len;
        return len;
    }
};