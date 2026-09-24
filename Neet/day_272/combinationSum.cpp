class Solution 
{
    public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        if (candidates.empty()) return {};
        vector<int> currPath = {};
        dfs(0, currPath, 0, target, candidates);
        return res;
    }

    private:
    vector<vector<int>> res;

    void dfs(int start, vector<int>& currPath, int currSum, int target, vector<int>& candidates)
    {
        if (currSum == target) {
            res.push_back(currPath);
            return;
        }

        for (int i=start; i<candidates.size(); i++) {
            int nextSum = currSum + candidates[i];
            if (nextSum > target) continue;
            currPath.push_back(candidates[i]);
            dfs(i, currPath, nextSum, target, candidates);
            currPath.pop_back();
        }
    }
};