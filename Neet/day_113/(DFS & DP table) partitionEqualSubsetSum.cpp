class Solution 
{
    public:
    bool canPartition(vector<int>& nums) 
    {
        if (nums.empty()) return false;
        int n = nums.size();

        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % 2 != 0) return false;

        int target = totalSum / 2;
        // this dp will be faster
        vector<vector<int>> memo(n, vector<int>(target+1, -1));

        return dfs(target, 0, 0, nums, memo);
    }

    private:
    bool dfs(int target, int currSum, int start, vector<int>& options, vector<vector<int>>& memo)
    {
        if (currSum == target) return true;
        if (currSum > target || start >= options.size()) return false;

        if (memo[start][currSum] != -1) return memo[start][currSum];

        for (int i=start; i<options.size(); i++) {
            currSum += options[i];
            if (dfs(target, currSum, i+1, options, memo)) {
                currSum -= options[i]; // also backtrack here
                memo[i+1][currSum] = true;
                return true;
            }
            currSum -= options[i];
        }
        memo[start][currSum] = false;
        return false;
    }
};