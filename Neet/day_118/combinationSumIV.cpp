class Solution 
{
    public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        return dfs(0, target, nums);

    }
    private:
    unordered_map<int, int> memo;

    int dfs(int currSum, int target, vector<int>& options)
    {
        if (currSum == target) return 1;
        if (memo.count(currSum)) return memo[currSum];

        int numOfWays = 0;
        for (int i=0; i<options.size(); i++) {
            currSum += options[i];
            if (currSum > target) {
                currSum -= options[i];
                continue;
            }

            numOfWays += dfs(currSum, target, options);
            currSum -= options[i];
        }
        memo[currSum] = numOfWays;
        return numOfWays;
    }
};