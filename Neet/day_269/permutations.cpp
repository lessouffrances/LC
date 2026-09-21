class Solution 
{
    public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        if (nums.empty()) return {};
        vector<int> currPath = {};
        dfs(currPath, nums);
        return res;
    }

    private:
    vector<vector<int>> res;
    void dfs(vector<int>& currPath, vector<int>& nums)
    {
        if (currPath.size() == nums.size()) {
            res.push_back(currPath);
            return;
        }

        // for each of the nums, if not in this currState
        // push back it and recurse
        for (int num : nums) {
            if (find(currPath.begin(), currPath.end(), num) == currPath.end()) {
                currPath.push_back(num);
                dfs(currPath, nums);
                currPath.pop_back();
            }
        }
    }
}; 