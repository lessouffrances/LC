class Solution 
{
    public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
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
            if (i>start && candidates[i] == candidates[i-1]) continue;
            int nextSum = currSum + candidates[i];
            if (nextSum > target) continue;
            currPath.push_back(candidates[i]);
            dfs(i+1, currPath, nextSum, target, candidates);
            currPath.pop_back();
        }
    }
};