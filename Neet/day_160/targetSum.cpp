



// Time: O(2^N)
// Space: O(N)

class Solution 
{
    public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        if (nums.empty()) return 0;
        return dfs(0, 0, target, nums);
    }

    private:
    int dfs(int currIdx, int currSum, int target, vector<int>& nums)
    {
        if (currIdx == nums.size()) {
            return (currSum == target) ? 1 : 0;
        }

        int numOfWays = 0;
        numOfWays += dfs(currIdx+1, currSum-nums[currIdx], target, nums);
        numOfWays += dfs(currIdx+1, currSum+nums[currIdx], target, nums);

        return numOfWays;
    }
};
