class Solution 
{
    public:
    int minCut(string s) 
    {
        buildPalindromeInfo(s);
        dfs(0, 0, s);
        return minCutNum == INT_MAX ? 0 : minCutNum;
    }

    private:
    vector<vector<bool>> dp;
    int minCutNum = INT_MAX;
    void dfs(int currIdx, int currCut, const string& s) 
    {
        if (currIdx == s.length()) {
            minCutNum = min(currCut-1, minCutNum);
            return;
        }

        for (int endIdx=currIdx; endIdx<s.length(); endIdx++) {
            if (!dp[currIdx][endIdx]) continue;
            dfs(endIdx+1, currCut+1, s);
        }
    }

    void buildPalindromeInfo(const string& s) 
    {
        int n = s.length();
        dp.assign(n, vector<bool>(n, false));

        for (int start=n-1; start>=0; start--) {
            for (int end=start; end<n; end++) {
                dp[start][end] = (s[start] == s[end] && (end-start <= 2 || dp[start+1][end-1]));
            }
        }
    }
};