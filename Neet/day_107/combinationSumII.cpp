class Solution 
{
    public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        if (candidates.empty()) return {};
        sort(candidates.begin(), candidates.end());
        vector<int> startPath;
        dfs(startPath, 0, 0, candidates, target);
        return res;
    }
    private:
    vector<vector<int>> res;
    void dfs(vector<int>& currPath, int currSum, int start, vector<int>& options, int target)
    {
        if (currSum == target) {
            res.push_back(currPath);
            return;
        }

        for (int i=start; i<options.size(); i++) {
            if (i>start && options[i] == options[i-1]) continue;
            if (currSum + options[i] > target) continue;
            
            currPath.push_back(options[i]);
            dfs(currPath, currSum+options[i], i+1, options, target);
            currPath.pop_back();
        }
    }
};