




class Solution 
{
    public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        if (nums.empty()) return {};
        sort(nums.begin(), nums.end());
        vector<int> currPath;
        dfs(currPath, nums);
        return res;
    }
    private:
    vector<vector<int>> res;
    // [1,2,3]
    
    // 0          1          2
    // (1,2,3)   (1,3)      (1)
    // 2          3          1
    // runtime: O(n * n!)
    void dfs(vector<int>& currPath, vector<int>& options)
    {
        if (options.empty()) {
            res.push_back(currPath);
            return;
        }

        for (int i=0; i<options.size(); i++) {
            // skip duplicates
            if (i>0 && options[i] == options[i-1]) continue;

            int selected = options[i];
            currPath.push_back(options[i]);
            // take the selected out of options for future calls
            auto iter = options.begin() + i;
            options.erase(iter);

            dfs(currPath, options);

            options.insert(iter, selected); // backtrack
            currPath.pop_back();
        }
    }

    void dfs(int start, vector<int>& nums)
    {
        if (start == nums.size()) 
        {
            res.push_back(nums);
            return;
        }
        
        unordered_set<int> seen;
        for (int i=start; i<nums.size(); i++) {
            if (seen.count(nums[i])) continue;
            seen.insert(nums[i]);
            swap(nums[start], nums[i]);
            dfs(start+1, nums);
            swap(nums[start], nums[i]);
        }
    }
};