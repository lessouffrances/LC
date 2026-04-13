

// Time: O(N * C(N, K))
// Space: O(N * C(N, K))

class Solution 
{
    public:
    vector<vector<int>> combine(int n, int k) 
    {
        vector<int> currPath;
        dfs(currPath, 1, k, n);
        return res;
    }
    private:
    vector<vector<int>> res;
    // dfs( {}, 1, k, n )
    void dfs(vector<int>& currPath, int currNum, int k, int n)
    {
        // we need the size of the currPath to be exactly k
        if (currPath.size() == k) {
            res.push_back(currPath);
            return;
        }

        // prune
        if (currNum > n) return;

        // take the currNum
        currPath.push_back(currNum);
        dfs(currPath, currNum+1, k, n);
        currPath.pop_back();

        // skip 
        dfs(currPath, currNum+1, k, n);
    }
};