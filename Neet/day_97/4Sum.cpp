class Solution 
{
    public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        if (nums.empty()) return {};

        sort(nums.begin(), nums.end());
        vector<int> startPath;
        dfs(startPath, nums, 0, 4, target);
        return res;
    }
    private:
    vector<vector<int>> res;
    void dfs(vector<int>& currPath, vector<int>& options, int start, int k, long long target)
    {
        int n = options.size();

        // base case is TwoSum
        if (k == 2) {
            int l = start, r = n-1;
            while (l < r) {
                long long sum = options[l] + options[r];

                if (sum < target) {
                    l++;
                } else if (sum > target) {
                    r--;
                } else {
                    // found a valid pair
                    currPath.push_back(options[l]);
                    currPath.push_back(options[r]);
                    res.push_back(currPath);
                    currPath.pop_back();
                    currPath.pop_back();

                    l++;
                    r--;

                    // skip duplicates
                    while (l < r && options[l] == options[l-1]) {
                        l++;
                    }
                    while (l < r && options[r] == options[r+1]) {
                        r--;
                    }
                }
            }
            return;
        }

        for (int i=start; i<n-k+1; i++) {
            if (i>start && options[i] == options[i-1]) continue;
            currPath.push_back(options[i]);
            dfs(currPath, options, i+1, k-1, target-options[i]);
            currPath.pop_back();
        }
    }
};