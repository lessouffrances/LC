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
        string currPath = "";
        dfs(0, 0, currPath, n);
        return res;
    }
    private:
    vector<string> res;

    void dfs(int numOfOpen, int numOfClose, string& currPath, int n)
    {
        // base case
        if (numOfOpen == n & numOfClose == n) {
            res.push_back(currPath);
            return;
        }

        // when we can add close?
        // when numOfClose < numOfOpen
        if (numOfClose < numOfOpen) {
            currPath.push_back(')');
            dfs(numOfOpen, numOfClose+1, currPath, n);
            currPath.pop_back();
        }


        if (numOfOpen < n) {
            currPath.push_back('(');
            dfs(numOfOpen+1, numOfClose, currPath, n);
            currPath.pop_back();
        }
    }
};