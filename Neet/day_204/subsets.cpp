class Solution 
{
    public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        if (nums.empty()) return { {} };
        vector<int> currPath = {};

        dfs(0, currPath, nums);
        return res;
    }

    private:
    vector<vector<int>> res;
    void dfs(int currIdx, vector<int>& currPath, vector<int>& nums)
    {
        if (currIdx == nums.size()) {
            res.push_back(currPath);
            return;
        }

        // take the currIdx 
        currPath.push_back(nums[currIdx]);
        dfs(currIdx+1, currPath, nums);
        currPath.pop_back(); // backtrack

        // skip
        dfs(currIdx+1, currPath, nums);
    }
};