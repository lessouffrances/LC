class Solution 
{
    public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        if (nums.empty()) return {};
        sort(nums.begin(), nums.end());
        vector<int> currPath = {};

        dfs(currPath, 0, target, 4, 0, nums);
        return res;
    }

    private:
    // currPath: incomplete 4-sum vector, in-progress
    // currSum: simply the accumulation of currPath
    // target: target for the current recursion
    // k: k-sum, what is the k
    // start: the start pos for the next recursion call
    // nums: options of numbers we can choose from
    vector<vector<int>> res;
    void dfs(vector<int>& currPath, long long currSum, long long target, int k, int start, vector<int>& nums)
    {
        // base case: when this problem became a two-sum
        if (k == 2) {
            // deal with a twosum problem
            int left = start;
            int right = nums.size()-1;

            while (left < right) {
                long long twoSum = nums[left]+nums[right];
                if (twoSum < target) {
                    left++;
                } else if (twoSum > target) {
                    right--;
                } else {
                    currPath.push_back(nums[left]);
                    currPath.push_back(nums[right]);
                    res.push_back(currPath);
                    currPath.pop_back();
                    currPath.pop_back();

                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left-1]) left++;
                    while (left < right && nums[right] == nums[right+1]) right--;
                }
            }
            return;
        }

        // recurse
        for (int i=start; i<nums.size(); i++) {
            // skip duplicates
            if (i>start && nums[i] == nums[i-1]) continue;

            currPath.push_back(nums[i]);
            dfs(currPath, currSum+nums[i], target-nums[i], k-1, i+1, nums);
            currPath.pop_back();
        }
    }
};