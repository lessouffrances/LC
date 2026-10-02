class Solution 
{
    public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
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

        for (int num : nums) {
            if (find(currPath.begin(), currPath.end(), num) == currPath.end()) {
                currPath.push_back(num);
                dfs(currPath, nums);
                currPath.pop_back();
            }
        }
    }
};