

// Time Complexity: O(2ⁿ)
// Unlike combinationSum 1, elements cannot be reused (i+1 instead of i). 
// This means each element is either in or out — exactly like subsets.

class Solution 
{
    public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        vector<int> currPath;
        dfs(currPath, 0, 0, candidates, target);
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
            // nums are sorted, dups are adjacent
            if (i>start && options[i] == options[i-1]) continue;

            int nextSum = currSum + options[i];
            if (nextSum > target) continue;

            currPath.push_back(options[i]);
            dfs(currPath, currSum+options[i], i+1, options, target);
            currPath.pop_back();
        }
    }
};