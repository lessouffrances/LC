



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

        // take the options[idx]
        currPath.push_back(options[idx]);
        dfs(currPath, idx+1, options);

        // backtrack
        currPath.pop_back();

        // skip 
        dfs(currPath, idx+1, options);
    }
};