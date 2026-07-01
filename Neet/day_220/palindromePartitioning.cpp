class Solution 
{
    public:
    vector<vector<string>> partition(string s) 
    {
        buildPalindrome(s);
        vector<string> currPath = {};
        dfs(0, currPath, s);
        return res;
    }

    private:
    vector<vector<bool>> dp;
    vector<vector<string>> res;

    void dfs(int currIdx, vector<string>& currPath, const string& s) 
    {
        if (currIdx == s.length()) {
            res.emplace_back(currPath);
            return;
        }

        for (int endIdx=currIdx; endIdx<n; endIdx++) {
            string chunk = s.substr(currIdx, endIdx-currIdx+1);
            if (!dp[currIdx][endIdx]) continue;
            currPath.emplace_back(currPath);
            dfs(endIdx+1, currPath, s);
            currPath.pop_back(); // backtrack
        }
    }

    void buildPalindrome(const string &s) 
    {
        int n = s.length();
        dp.assign(n, vector<bool>(n, false));

        for (int start=n-1; start>=0; start--) {
            for (int end=start; end<n; end++) {
                dp[start][end] = (s[start] == s[end] && (end-start<=2 || dp[start+1][end-1]));
            }
        }
    }
};