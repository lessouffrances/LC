class Solution 
{
    public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        if (nums.empty()) return {};
        dfs(0, nums);
        return vector<vector<int>>(res.begin(), res.end());
    }

    private:
    set<vector<int>> res;
    void dfs(int start, vector<int>& nums) 
    {
        if (start == nums.size()) {
            res.insert(nums);
            return;
        }

        for (int i=start; i<nums.size(); i++) {
            swap(nums[i], nums[start]);
            dfs(start+1, nums);
            swap(nums[i], nums[start]);
        }
    }
};