

// Time: O(N * C(n, k))
// Space: O(N * C(n, k))
class Solution 
{
    public:
    vector<vector<int>> combine(int n, int k) 
    {
        vector<int> currPath;
        dfs(1, currPath, n, k);
        return res;
    }

    private:
    vector<vector<int>> res;
    void dfs(int currNum, vector<int>& currPath, int n, int k)
    {
        // base case
        if (currPath.size() == k) {
            res.push_back(currPath);
            return;
        }

        // prune
        if (currNum > n) return;

        // take the currNum
        currPath.push_back(currNum);
        dfs(currNum+1, currPath, n, k);
        currPath.pop_back();

        // skip the currNun
        dfs(currNum+1, currPath, n, k);
    }
};