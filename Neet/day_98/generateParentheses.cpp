class Solution 
{
    public:
    vector<string> generateParenthesis(int n) 
    {
        if (n == 0) return {};

        string startPath = "";
        dfs(startPath, n, 0, 0);
        return res;
    }
    private:
    vector<string> res;
    void dfs(string currPath, int n, int numClose, int numOpen)
    {
        if (numClose == n && numOpen == n) {
            res.push_back(currPath);
            return;
        }

        // if numClose < numOpen
        if (numClose < numOpen) {
            currPath.push_back(')');
            dfs(currPath, n, numClose+1, numOpen);
            currPath.pop_back();
        }

        if (numOpen < n) {
            currPath.push_back('(');
            dfs(currPath, n, numClose, numOpen+1);
            currPath.pop_back();
        }
    }
};