class Solution 
{
    public:
    bool canPartition(vector<int>& nums) 
    {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % 2 != 0) return false;
        int target = totalSum / 2;
        return dfs(0, 0, target, nums);
    }

    private:
    unordered_map<string, bool> memo;
    bool dfs(int start, int currSum, int target, vector<int>& nums) {
        // base case
        if (currSum == target) return true;
        if (currSum > target) return false;

        string key = to_string(start) + "," + to_string(currSum);
        if (memo.count(key)) return memo[key];
        
        for (int i=start; i<nums.size(); i++) {
            currSum += nums[i];
            if (dfs(i+1, currSum, target, nums)) return memo[key] = true;
            currSum -= nums[i]; // backtrack
        }
        return memo[key] = false;
    }
};