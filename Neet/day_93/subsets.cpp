class Solution 
{
    public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        if (nums.empty()) return {};

        vector<int> startPath;
        dfs(startPath, 0, nums);
        return res;
    }
    private:
    vector<vector<int>> res;
    void dfs(vector<int>& currPath, int idx, vector<int>& options)
    {
        if (idx == options.size()) {
            res.push_back(currPath);
            return;
        }

        // for a num, 2 choices, take or skip
        currPath.push_back(options[i]);
        dfs(currPath, idx+1, options);

        currPath.pop_back();
        dfs(currPath, idx+1, options);
    }
};