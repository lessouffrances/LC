class Solution 
{
    public:
    int minCut(string s) 
    {
        if (s.empty()) return 0;
        int n = s.length();

        // precompute isPalin[i][j]
        isPalin.assign(n, vector<bool>(n, false));
        for (int end = n-1; end >= 0; end--) {
            for (int start = end; start < n; start++) {
                isPalin[end][start] = (s[end] == s[start]) && (start-end <= 2 || isPalin[end+1][start-1]);
            }
        }

        memo.assign(n, -1);
        return dfs(0, s) - 1;
    }

    private:
    vector<int> memo;
    vector<vector<bool>> isPalin;

    int dfs(int currIdx, const string& s)
    {
        if (currIdx == (int)s.length()) return 0;
        if (memo[currIdx] != -1) return memo[currIdx];

        int minSplits = INT_MAX;
        for (int i = currIdx; i < (int)s.length(); i++) {
            if (!isPalin[currIdx][i]) continue;
            int res = dfs(i+1, s);
            if (res != INT_MAX)
                minSplits = min(minSplits, 1 + res);
        }
        return memo[currIdx] = minSplits;
    }
};