class Solution 
{
    public:
    vector<vector<int>> combine(int n, int k) 
    {
        vector<int> currPath = {};
        dfs(1, currPath, n, k);
        return res;
    }
    
    private:
    vector<vector<int>> res;

    void dfs(int currNum, vector<int>& currPath, int n, int k) 
    {
        if (currPath.size() == k) {
            res.emplace_back(currPath);
            return;
        }
        
        if (currNum > n) return;

        // take 
        currPath.emplace_back(currNum);
        dfs(currNum+1, currPath, n, k);
        currPath.pop_back();

        // skip
        dfs(currNum+1, currPath, n, k);
    }
};