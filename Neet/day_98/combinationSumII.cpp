class Solution 
{
    public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        if (candidates.empty()) return {};

        sort(candidates.begin(), candidates.end());
        vector<int> startPath;
        dfs(startPath, 0, target, 0, candidates);
        return res;
    }
    private:
    vector<vector<int>> res;
    void dfs(vector<int>& currPath, int currSum, int target, int start, vector<int>& options) 
    {
        if (currSum == target) {
            res.push_back(currPath);
            return;
        }

        for (int i=start; i<options.size(); i++) {
            if (i>start && options[i] == options[i-1]) continue;
            int selected = options[i];
            if (currSum + selected > target) continue;
            currPath.push_back(selected);
            dfs(currPath, currSum+selected, target, i+1, options);
            currPath.pop_back();
        }
    }
};