class Solution 
{
    public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        return dfs(0, 0, nums, target);
    }

    private:
    int dfs(int currIdx, int currSum, vector<int>& nums, int target) 
    {
        if (currIdx == nums.size()) {
            return currSum == target ? 1 : 0;
        }

        int ways = 0;
        // +/- currIdx
        ways += dfs(currIdx+1, currSum+nums[currIdx], nums, target);
        ways += dfs(currIdx+1, currSum-nums[currIdx], nums, target);
        return ways;
    }
};