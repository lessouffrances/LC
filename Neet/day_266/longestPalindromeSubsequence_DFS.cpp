class Solution 
{
    public:
    int longestPalindromeSubseq(string s) 
    {
        int n = s.length();
        memo.assign(n, vector<int>(n, -1));
        return dfs(0, n-1, s);
    }

    private:
    // returns the LPS inside the s[start:end], inclusive
    vector<vector<int>> memo;
    int dfs(int start, int end, const string& s)
    {
        if (memo[start][end] != -1) return memo[start][end];
        if (start == end) return 1;
        if (start > end) return 0;

        if (s[start] == s[end]) {
            memo[start][end] = dfs(start+1, end-1, s) + 2;
        } else {
            memo[start][end] = max(dfs(start+1, end, s), dfs(start, end-1, s));
        }
        return memo[start][end];
    }
};