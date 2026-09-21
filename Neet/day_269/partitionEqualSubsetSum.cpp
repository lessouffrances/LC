


class Solution 
{
    public:
    bool canPartition(vector<int>& nums) 
    {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0) return false;
        int target = total / 2;

        vector<bool> dp(target+1, false); // check if some amount can be made
        dp[0] = true;

        // only need to see if target can be build,
        // if target can be build once, 
        // then the rest of the numbers must sum to be target
        for (int i=0; i<n; i++) {
            for (int currAmount=target; currAmount>=nums[i]; currAmount--) {
                // if currAmount-nums[i] can be built, then currAmount can be built
                if (dp[currAmount-nums[i]]) {
                    dp[currAmount] = true;
                }
            }
        }
        return dp[target];
    }
};