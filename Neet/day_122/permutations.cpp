



// Time Complexity: O(n * n!)
class Solution 
{
    public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        if (nums.empty()) return {};
        vector<int> currPath;
        dfs(currPath, nums);
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
            // mutate the options
            auto iter = options.begin()+i;
            options.erase(iter);

            dfs(currPath, options);

            // backtrack
            currPath.pop_back();
            options.insert(iter, selected);
        }
    }
};