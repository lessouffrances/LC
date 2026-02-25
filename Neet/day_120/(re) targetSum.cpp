class Solution 
{
    public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        if (nums.empty()) return 0;
        return dfs(0, 0, nums, target);
    }
    private:
    unordered_map<string, int> memo;
    int dfs(int idx, int currSum, vector<int>& options, int target) 
    {
        if (idx == options.size()) {
            return currSum == target ? 1 : 0;
        }

        string key = getPathKey(idx, currSum);
        if (memo.count(key)) return memo[key];

        // assign '+' to the currIdx;
        int plus = dfs(idx+1, currSum+options[idx], options, target);

        // assign '-' to the currIdx;
        int minus = dfs(idx+1, currSum-options[idx], options, target);

        memo[key] = plus+minus;
        return plus+minus;
    }
    private:
    string getPathKey(int idx, int currSum) 
    {
        return to_string(idx) + "->" + to_string(currSum);
    }
};