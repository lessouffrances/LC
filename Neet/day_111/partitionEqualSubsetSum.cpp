class Solution 
{
    public:
    bool canPartition(vector<int>& nums) 
    {
        if (nums.empty()) return false;

        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        if (totalSum % 2 != 0) return false;

        int subsetSum = totalSum / 2;
        return dfs(0, 0, nums, subsetSum);
    }
    private:
    unordered_map<string, bool> memo;
    bool dfs(int currSum, int start, vector<int>& options, int subsetSum) 
    {
        if (currSum == subsetSum) return true;
        string key = to_string(start) + "->" + to_string(currSum);

        if (memo.count(key)) return memo[key];
        if (currSum > subsetSum) return false;

        for (int i=start; i<options.size(); i++) {
            currSum += options[i];
            if (dfs(currSum, i+1, options, subsetSum)) {
                memo[key] = true;
                return true;
            }
            currSum -= options[i];
        }
        memo[key] = false;
        return false;
    }
};