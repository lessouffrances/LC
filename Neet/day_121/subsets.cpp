class Solution 
{
    public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        if (nums.empty()) return {};

        sort(nums.begin(), nums.end());
        vector<int> currPath;
        dfs(0, currPath, nums);
        return res;
    }
    private:
    vector<vector<int>> res;
    void dfs(int currIdx, vector<int>& currPath, vector<int>& options)
    {
        if (currIdx == options.size()) {
            res.push_back(currPath);
            return;
        }

        // take the num at currIdx
        currPath.push_back(options[currIdx]);
        dfs(currIdx+1, currPath, options);
        currPath.pop_back();

        // skip the num at currIdx
        dfs(currIdx+1, currPath, options);
    }
};