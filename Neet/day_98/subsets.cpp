class Solution 
{
    public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        if (nums.empty()) return {};
        vector<int> startPath;
        dfs(0, startPath, nums);
        return res;
    }
    private:
    vector<vector<int>> res;
    void dfs(int idx, vector<int>& currPath, vector<int>& options)
    {
        if (idx == options.size()) {
            res.push_back(currPath);
            return;
        }

        // take the idx 
        currPath.push_back(options[idx]);
        dfs(idx+1, currPath, options);
        currPath.pop_back();

        // skip the idx but increment idx
        dfs(idx+1, currPath, options);
    }
};