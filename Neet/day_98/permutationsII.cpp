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
            if (i>0 && options[i] == options[i-1]) continue;

            int selected = options[i];
            currPath.push_back(selected);
            auto iter = options.begin() + i;
            options.erase(iter);
            
            dfs(currPath, options);

            currPath.pop_back();
            options.insert(iter, selected);
        }
    }
    
};
