class Solution 
{
    public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        return dfs(0, 0, nums, target);
    }

    private:

    int dfs(int currSum, int currIdx, vector<int>& nums, int target)
    {
        if (currIdx == nums.size()) {
            return currSum == target ? 1 : 0;
        }

        int ways = 0;
        ways += dfs(currSum+nums[currIdx], currIdx+1, nums, target);
        ways += dfs(currSum-nums[currIdx], currIdx+1, nums, target);

        return ways;
    }
};