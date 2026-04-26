class Solution 
{
    public:
    vector<string> generateParenthesis(int n) 
    {
        if (n == 0) return {};
        string currPath = "";
        dfs(0, 0, currPath, n);
        return res;
    }

    private:
    vector<string> res;

    void dfs(int numOpen, int numClose, string currPath, int n)
    {
        if (numOpen == n && numClose == n) {
            res.push_back(currPath);
            return;
        }

        // if numClose < num
        if (numClose < numOpen) {
            currPath.push_back(')');
            dfs(numOpen, numClose+1, currPath, n);
            currPath.pop_back();
        }

         // if numOpen < n
        if (numOpen < n) {
            currPath.push_back('(');
            dfs(numOpen+1, numClose, currPath, n);
            currPath.pop_back();
        } 
    }
};