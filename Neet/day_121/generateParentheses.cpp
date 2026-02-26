class Solution 
{
    public:
    vector<string> generateParenthesis(int n) 
    {
        if (n == 0) return {};
        string startPath = "";
        dfs(0, 0, n, startPath);
        return res;
    }
    private:
    vector<string> res;
    void dfs(int numOpen, int numClose, int n, string& currPath)
    {
        if (numOpen == n && numClose == n) {
            res.push_back(currPath);
            return;
        }

        // ()(, ((()
        if (numOpen > numClose) {
            currPath.push_back(')');
            dfs(numOpen, numClose+1, n, currPath);
            currPath.pop_back();
        }

        if (numOpen < n) {
            currPath.push_back('(');
            dfs(numOpen+1, numClose, n, currPath);
            currPath.pop_back();
        }
    }
};