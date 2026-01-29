class Solution 
{
    public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        vector<int> startPath;
        dfs(startPath, nums);
        return res;
    }
    private:
    vector<vector<int>> res;
    void dfs(vector<int>& currPath, vector<int>& options) 
    {
        if (options.empty()) {
            res.push_back(currPath);
            return;
        }

        for (int i=0; i<options.size(); i++) {
            if (i > 0 && options[i] == options[i-1]) continue;

            int selected = options[i];
            auto it = options.begin()+i;
            options.erase(it);
            currPath.push_back(selected);
            dfs(currPath, options);
            options.insert(it, selected);
            currPath.pop_back();
        }
    }
};