class Solution 
{
    public:
    // "((()))"
    // in-process rules:
    // "( ( ( ) ) ) )": rule# 1, numOfClose cannot exceed numOfOpen

    // given n = 3
    // " ( ( ( ( ": rule# 2, numOfOpen cannot exceed given n   
    vector<string> generateParenthesis(int n) 
    {
        if (n == 0) return {};

        string currPath = "";
        dfs(0, 0, currPath, n);
        return res;
    }

    private:
    vector<string> res;
    void dfs(int numOfClose, int numOfOpen, string& currPath, int n)
    {
        if (numOfClose == n && numOfOpen == n) {
            res.push_back(currPath);
            return;
        }

        // when we can add a close bracket
        if (numOfClose < numOfOpen) {
            currPath.push_back(')');
            dfs(numOfClose+1, numOfOpen, currPath, n);
            currPath.pop_back();
        }

        // when we can add an open bracket
        if (numOfOpen < n) {
            currPath.push_back('(');
            dfs(numOfClose, numOfOpen+1, currPath, n);
            currPath.pop_back();
        }
    }
};