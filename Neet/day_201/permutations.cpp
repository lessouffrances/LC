class Solution 
{
    public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        dfs(0, nums);
        return res;
    }
    private:
    vector<vector<int>> res;
    void dfs(int start, vector<int>& nums)
    {
        if (start == nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int i=start; i<nums.size(); i++) {
            swap(nums[i], nums[start]);
            dfs(start+1, nums);
            swap(nums[i], nums[start]);
        }
    }
};