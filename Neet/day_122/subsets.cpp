


// O(n * 2^n): n for linear copy, 2^n for binary decision

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

    // void dfs(vector<int>& currPath, int currIdx, int start, vector<int>& options)
    // {
    //     res.push_back(currPath);

    //     for (int i=start; i<options.size(); i++) {
    //         if (i>start && options[i] == options[i-1]) continue;
    //         currPath.push_back(options[i]);
    //         dfs(currPath, currIdx+1, i+1, options);
    //         currPath.pop_back();
    //     }
    // }
};