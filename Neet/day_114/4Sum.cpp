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

        // base case
        if (k == 2) {
            int left = start, right = n-1;
            while (left < right) {
                long long twoSum = options[left] + options[right];

                if (twoSum > target) { // target has been shrinked to twoSum level by dfs
                    right--;
                } else if (twoSum < target) {
                    left++;
                } else {
                    currPath.push_back(options[left]);
                    currPath.push_back(options[right]);

                    res.push_back(currPath);

                    currPath.pop_back();
                    currPath.pop_back();
                    
                    while (left < right && options[left] == options[left+1]) left++;
                    while (left < right && options[right] == options[right+1]) right--;
                    left++;
                    right--;
                }
            }
            return;
        }

        for (int i=start; i<n; i++) {
            if (i-1>=start && options[i] == options[i-1]) continue;
            currPath.push_back(options[i]);
            dfs(currPath, options, i+1, k, target-options[i]);
            currPath.pop_back();
        }
    }
};