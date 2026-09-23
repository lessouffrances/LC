class Solution 
{
    public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<int> currPath = {};
        dfs(0, 0, target, currPath, candidates);
        return res;
    }

    private:
    vector<vector<int>> res;
    void dfs(int start, int currSum, int target, vector<int>& currPath, vector<int>& candidates)
    {
        if (currSum == target) {
            res.push_back(currPath);
            return;
        }

        for (int i=start; i<candidates.size(); i++) {
            int nextSum = currSum+candidates[i];
            if (nextSum > target) continue;
            currPath.push_back(candidates[i]);
            dfs(i, nextSum, target, currPath, candidates);
            currPath.pop_back();
        }
    }
};