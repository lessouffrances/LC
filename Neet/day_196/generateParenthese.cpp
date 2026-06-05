class Solution 
{
    public:
    vector<string> generateParenthesis(int n) 
    {
        dfs("", 0, 0, n);
        return res;
    }
    private:
    vector<string> res;
    void dfs(string currPath, int numOpen, int numClose, int n)
    {
        if (numOpen == n && numClose == n) {
            res.push_back(currPath);
            return;
        }

        if (numClose < numOpen) {
            currPath.push_back(')');
            dfs(currPath, numOpen, numClose+1, n);
            currPath.pop_back();
        }

        if (numOpen < n) {
            currPath.push_back('(');
            dfs(currPath, numOpen+1, numClose, n);
            currPath.pop_back();
        }
    }
};