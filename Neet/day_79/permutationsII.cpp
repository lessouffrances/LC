class Solution 
{
    public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        if (nums.empty()) return {};
        vector<int> startPerm;
        dfs(startPerm, nums);
        vector<vector<int>> res;
        for (auto& perm : permSet) {
            res.push_back(perm);
        }
        return res;
    }

    private:
    set<vector<int>> permSet;
    void dfs(vector<int>& currPerm, vector<int>& options)
    {
        if (options.empty()) {
            permSet.insert(currPerm);
            return;
        }

        for (int i=0; i<options.size(); i++) {
            int selected = options[i];
            auto iter = options.begin()+i;
            options.erase(iter);
            currPerm.push_back(selected);
            dfs(currPerm, options);
            // backtrack
            options.insert(iter, selected);
            currPerm.pop_back();
        }
    }
};