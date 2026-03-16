

// Time: O(2^n · n)

// With duplicates, the number of unique subsets is less than 2^n,
// but the worst case (all unique) is still 2^n subsets
// Each subset takes O(n) to copy into res
// Sorting is O(n log n), dominated by the above

// Space: O(2^n · n)
// res stores all unique subsets → O(2^n · n) worst case
// Recursion stack: O(n)
// currPath: O(n)
class Solution 
{
    public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        if (nums.empty()) return {};
        sort(nums.begin(), nums.end());
        vector<int> currPath;
        dfs(currPath, 0, 0, nums);
        return res;
    }
    private:
    vector<vector<int>> res;
    void dfs(vector<int>& currPath, int currIdx, int start, vector<int>& options)
    {
        // each state is a subset
        res.push_back(currPath);

        for (int i=start; i<options.size(); i++) {
            if (i>start && options[i] == options[i-1]) continue;
            currPath.push_back(options[i]);
            dfs(currPath, currIdx+1, i+1, options);
            currPath.pop_back();
        }
    }
};