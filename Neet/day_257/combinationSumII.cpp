class Solution 
{
    public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        if (candidates.empty()) return {};

        sort(candidates.begin(), candidates.end());
        vector<int> currPath;
        dfs(currPath, 0, 0, target, candidates);
        return res;
    }
    private:
    vector<vector<int>> res;
    void dfs(vector<int>& currPath, int currSum, int start, int target, vector<int>& options)
    {
        if (currSum == target) {
            res.push_back(currPath);
            return;
        }

        for (int i=start; i<options.size(); i++) {
            if (i>start && options[i] == options[i-1]) continue;

            int nextSum = currSum+options[i];
            if (nextSum > target) continue;

            currPath.push_back(options[i]);
            dfs(currPath, nextSum, i+1, target, options);
            currPath.pop_back();
        }
    }
};