



// Time: O(N! * N)
// Space: O(N! * N)

class Solution 
{
    public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        if (nums.empty()) return {};
        sort(nums.begin(), nums.end());
        dfs(0, nums);
        return res;
    }
    private:
    vector<vector<int>> res;
    void dfs(int start, vector<int>& nums)
    {
        if (start == nums.size()) {
            res.push_back(res);
            return;
        }

        // prevent from duplication
        unordered_set<int> seen;
        for (int i=start; i<nums.size(); i++) {
            if (seen.count(nums[i])) continue;
            seen.insert(nums[i]);
            swap(nums[i], nums[start]);
            dfs(start+1, nums);
            swap(nums[i], nums[start]);
        }
    }
};