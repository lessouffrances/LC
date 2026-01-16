class Solution 
{
    public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        vector<int> startPath;
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

        for (int i=start; i<options.size(); i++) {
            if (i > start && options[i] == options[i-1]) continue;

            int selected = options[i];
            currPath.push_back(selected);
            dfs(i+1, currPath, options, target);
            currPath.pop_back();
        }
    }
};