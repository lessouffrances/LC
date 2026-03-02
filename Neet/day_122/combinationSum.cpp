
// Time Complexity: O(n^(t/m))
// Where:
// n = number of candidates
// t = target value
// m = smallest candidate value

class Solution 
{
    public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        if (candidates.empty()) return {};

        sort(candidates.begin(), candidates.end());
        vector<int> currPath;
        dfs(currPath, 0, 0, candidates, target);
        return res;
    }
    private:
    vector<vector<int>> res;
    //        i
    // [1, 2, 3, 6, 7, 9]    target: 8
    void dfs(vector<int>& currPath, int currSum, int start, vector<int>& options, int target)
    {
        if (currSum == target) {
            res.push_back(currPath);
            return;
        }

        for (int i=start; i<options.size(); i++) {
            if (i>start && options[i] == options[i-1]) continue;

            int nextSum = currSum + options[i];
            if (nextSum > target) continue; // prune

            currSum += options[i];
            currPath.push_back(options[i]);
            dfs(currPath, currSum, i+1, options, target);
            currSum -= options[i]; // backtarck
            currPath.pop_back();
        }
    }
};