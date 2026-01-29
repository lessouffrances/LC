class Solution 
{
    public:
    vector<string> generateParenthesis(int n) 
    {
        if (n == 0) return {};
        string startPath = "";
        dfs(startPath, 0, 0, n);
        return res;
    }
    private:
    vector<string> res;
    void dfs(string& currPath, int numOpen, int numClose, int n) 
    {
        if (numClose == n && numOpen == n) {
            res.push_back(currPath);
            return;
        }

        // only when close < open can we push close
        if (numClose < numOpen) {
            currPath.push_back(')');
            dfs(currPath, numOpen, numClose+1);
            currPath.pop_back();
        }

        // following that
        if (numOpen < n) {
            currPath.push_back('(');
            dfs(currPath, numOpen+1, numClose);
            currPath.pop_back();
        }
    }
};