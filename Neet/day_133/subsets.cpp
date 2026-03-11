


// Time: O (N * 2^N)
// Space: O (N * 2^N)


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

        // take this currIdx num
        currPath.push_back(options[currIdx]);
        dfs(currPath, currIdx+1, options);
        currPath.pop_back();

        // do not take
        dfs(currPath, currIdx+1, options);
    }
};