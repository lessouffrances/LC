class Solution 
{
    public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<int> startPath = {};
        dfs(0, startPath, candidates, target);
        return res;
    }
    private:
    vector<vector<int>> res;
    void dfs(int start, vector<int>& currPath, vector<int>& options, int target)
    {
        int currSum = accumulate(currPath.begin(), currPath.end(), 0);
        if (currSum == target) {
            res.push_back(currPath);
            return;
        }

        if (currSum > target) return;

        int n = options.size();
        for (int i=start; i<n; i++) {
            currPath.push_back(options[i]);
            dfs(i, currPath, options, target);
            currPath.pop_back(); 
        }
    }
};