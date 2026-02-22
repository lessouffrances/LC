class Solution 
{
    public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        count = 0;
        dfs(0, nums, target);
        return count;
    }
    private:
    int count = 0;
    void dfs(long long currSum, vector<int>& options, int target)
    {
        if (currSum == target) {
            count++;
            return;
        }

        for (int i = 0; i < options.size(); i++) {
            currSum += options[i];
            if (currSum > target) {
                currSum -= options[i];
                continue;
            }
            dfs(currSum, options, target);
            currSum -= options[i];
        }
    }
};