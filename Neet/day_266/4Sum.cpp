class Solution 
{
    public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        if (nums.empty()) return {};

        sort(nums.begin(), nums.end());
        vector<int> currPath = {};
        dfs(0, currPath, 0, target, 4, nums);
        return res;
    }

    private:
    vector<vector<int>> res;

    void dfs(int start, vector<int>& currPath, long long currSum, 
        long long target, int k, vector<int>& nums)
    {
        if (k == 2) {
            int left = start, right = nums.size()-1;
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

        for (int i=start; i<nums.size(); i++) {
            if (i>start && nums[i] == nums[i-1]) continue;
            currPath.push_back(nums[i]);
            dfs(i+1, currPath, currSum+nums[i], target-nums[i], k-1, nums);
            currPath.pop_back();
        }
    }
};