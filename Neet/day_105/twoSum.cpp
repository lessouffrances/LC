











class Solution 
{
    public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        if (nums.empty()) return {};
        int n = nums.size();

        unordered_map<int, int> seen;
        for (int i=0; i<n; i++) {
            int diff = target - nums[i];
            if (seen.count(diff)) {
                return {i, seen[diff]};
            }
            seen[nums[i]] = i;
        }
        return {-1, -1};
    }
};