

// Time: O(n^(T/M)) where T = target and M = smallest candidate 
// — that's the maximum depth of the recursion tree, with n branches at each level.
// Space: O(T/M) — maximum recursion depth (longest path is target divided by smallest candidate). 

class Solution 
{
    public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        if (candidates.empty()) return {};
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
            int nextSum = currSum + options[i];
            if (nextSum > target) continue;

            currSum += options[i];
            currPath.push_back(options[i]);
            dfs(currPath, currSum, i, target, options);
            currSum -= options[i];
            currPath.pop_back();
        }
    }
};