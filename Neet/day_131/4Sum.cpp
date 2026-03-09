class Solution 
{
    public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        if (nums.empty()) return {};
        sort(nums.begin(), nums.end());
        vector<int> currPath;
        dfs(currPath, nums, 0, 4, target);
        return res;
    }
    private:
    vector<vector<int>> res;

    void dfs(vector<int>& currPath, vector<int>& options, int start, int k, long long target)
    {
        int n = options.size();

        if (k == 2) {
            int left = start, right = n-1;
            while (left < right) {
                long long twoSum = options[left]+options[right];

                if (twoSum > target) {
                    right--;
                } else if (twoSum < target) {
                    left++;
                } else {
                    currPath.push_back(options[left]);
                    currPath.push_back(options[right]);

                    res.push_back(currPath);
                    currPath.pop_back();
                    currPath.pop_back();

                    left++;
                    right--;

                    while (left<right && options[left] == options[left-1]) left++;
                    while (left<right && options[right] == options[right+1]) right--;
                    
                }
            } 
            return; // important!
        } 

        for (int i=start; i<n; i++) {
            if (i>start && options[i-1] == options[i]) continue;
            currPath.push_back(options[i]);
            dfs(currPath, options, i+1, k-1, target-options[i]);
            currPath.pop_back();
        }
    }
};