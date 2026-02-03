class Solution 
{
    public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        if (nums.empty()) return {};
        vector<int> startPath;
        dfs(startPath, nums);

        vector<vector<int>> res;
        for (auto& perm : permSet) {
            res.push_back(perm);
        }
        return res;
    }

    private:
    set<vector<int>> permSet;
    void dfs(vector<int>& currPath, vector<int>& options)
    {
        if (options.empty()) {
            permSet.insert(currPath);
            return;
        }

        for (int i=0; i<options.size(); i++) {
            int selected = options[i];
            auto iter = options.begin() + i;
            options.erase(iter);
            currPath.push_back(selected);

            dfs(currPath, options);

            currPath.pop_back();
            options.insert(iter, selected);
        }
    }
};