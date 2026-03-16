

// Time: O(2^n · n)
// 2^n subsets total, each takes O(n) to copy into res
// The recursion tree has 2^n leaves and 2^n - 1 internal nodes → O(2^n) nodes total, 
// O(1) work per node (excluding copies)

// Space: O(2^n · n)
// res stores 2^n subsets, average length n/2 → O(2^n · n)
// Recursion stack: O(n)
// currPath: O(n)
class Solution 
{
    public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        if (nums.empty()) return {};
        vector<int> currPath;
        dfs(currPath, 0, nums);
        return res;
    }
    
    private:
    vector<vector<int>> res;
    void dfs(vector<int>& currPath, int currIdx, vector<int>& options) 
    {
        if (currIdx == options.size()) {
            res.push_back(currPath);
            return;
        }

        // take the currIdx
        currPath.push_back(options[currIdx]);
        dfs(currPath, currIdx+1, options);
        currPath.pop_back();

        // skip the currIdx
        dfs(currPath, currIdx+1, options);
    }
};