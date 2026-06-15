class Solution 
{
    public:
    int minCut(string s) 
    {
        if (s.length() == 0) return 0;
        int n = s.length();

        precomputePalin(s);
        memo.assign(n, INT_MAX);

        return dfs(0, s)-1;
    }

    private:
    vector<int> memo; // for each endIdx, numOfMinCuts
    vector<vector<bool>> isPalin;

    int dfs(int currIdx, const string& s) 
    {
        if (currIdx == s.length()) return 0;

        if (memo[currIdx] != INT_MAX) return memo[currIdx];
        int minSplit = INT_MAX;

        for (int i=currIdx; i<s.length(); i++) {
            if (!isPalin[currIdx][i]) continue;
            int res = dfs(i+1, s);
            if (res != INT_MAX) {
                minSplit = min(minSplit, 1+res);
            }
        }
        return memo[currIdx] = minSplit;
    }

    void precomputePalin(const string& s)
    {
        int n = s.length();
        isPalin.assign(n, vector<bool>(n, false));

        for (int start=n-1; start >= 0; start--) {
            for (int end=start; end<n; end++) {
                isPalin[start][end] = (s[start] == s[end]) && (end-start <= 2 || isPalin[start+1][end-1]);
            }
        }
    }
};