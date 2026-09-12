class Solution 
{
    public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        if (nums.empty()) return {};
        sort(nums.begin(), nums.end());
        vector<int> currPath = {};
        dfs(currPath, 0, 0, nums);
        return res;
    }

    private:
    vector<vector<int>> res;
    void dfs(vector<int>& currPath, int currIdx, int start, vector<int>& options)
    {
        res.push_back(currPath); // each currPath is a subset
        
        for (int i=start; i<options.size(); i++) {
            if (i>start && options[i] == options[i-1]) continue;
            currPath.push_back(options[i]);
            dfs(currPath, currIdx+1, i+1, options);
            currPath.pop_back();
        }
    }
};