class Solution 
{
    public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        if (nums.empty()) return {};
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;

        for (int i=0; i<n-2; i++) {
            if (i >= 1 && nums[i] == nums[i-1]) continue;
            int left = i+1, right = n-1;
            int target = -nums[i];

            while (left < right) {
                int twoSum = nums[left] + nums[right];
                if (twoSum > target) {
                    right--;
                } else if (twoSum < target) {
                    left++;
                } else {
                    // find a valid triplet
                    res.push_back( {nums[i], nums[left], nums[right]} );
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left-1]) left++;
                    while (left < right && nums[right] == nums[right+1]) right--;
                }
            }
        }
        return res;
    }
};