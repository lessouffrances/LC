class Solution 
{
    public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        if (nums.empty()) return {};
        dfs(0, nums);
        return vector<vector<int>>(perms.begin(), perms.end());
    }

    private:
    set<vector<int>> perms;
    void dfs(int start, vector<int>& nums)
    {
        if (start == nums.size()) {
            perms.insert(nums);
            return;
        }

        for (int i=start; i<nums.size(); i++) {
            swap(nums[start], nums[i]);
            dfs(start+1, nums);
            swap(nums[start], nums[i]);
        }
    }
};