class Solution 
{
    public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        if (nums.empty()) return {};

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
            int selected = options[i];
            currPath.push_back(selected);

            auto it = options.begin()+i;
            options.erase(it);

            dfs(currPath, options);

            options.insert(it, selected); //backtrack
            currPath.pop_back();
        }

    }
};