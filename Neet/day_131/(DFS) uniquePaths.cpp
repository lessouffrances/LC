class Solution 
{
    public:
    int uniquePaths(int m, int n) 
    {
        memo.assign(m, vector<int>(n, -1));
        return dfs(0, 0, m, n);
    }
    private:
    vector<pair<int, int>> DIRS = { {0,1}, {1,0} };
    vector<vector<int>> memo; // the memo is necessary, otherwise TLE

    int dfs(int row, int col, int m, int n)
    {
        if (row == m-1 && col == n-1) return 1;
        if (memo[row][col] != -1) return memo[row][col];

        int numOfWays = 0;
        for (auto& DIR : DIRS) {
            int newR = row + DIR.first;
            int newC = col + DIR.second;

            if (newR<0 || newR>=m || newC<0 || newC>=n) continue;
            numOfWays += dfs(newR, newC, m, n);
        }
        memo[row][col] = numOfWays;
        return numOfWays;
    }
};