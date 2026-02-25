


class Solution 
{
    public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {

        return dfs(nums, 0, 0, target);
    }
    private:
    unordered_map<string, int> memo; // key -> numOfWays
    int dfs(vector<int>& options, int idx, int currSum, int target)
    {
        // base case
        if (idx == options.size()) {
            return (currSum == target) ? 1 : 0;   
        }
        // early-return
        string key = getPathKey(idx, currSum);
        if (memo.count(key)) return memo[key];
        
        // assign '+' to this idx
        int plusWays = dfs(options, idx+1, currSum+options[idx], target);

        // assign '-' to this idx
        int minusWays = dfs(options, idx+1, currSum-options[idx], target);

        memo[key] = plusWays+minusWays;
        return plusWays+minusWays;
    }

    string getPathKey(int idx, int currSum)
    {
        return to_string(idx) + "->" + to_string(currSum);
    }
};