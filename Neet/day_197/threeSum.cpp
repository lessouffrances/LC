class Solution 
{
    public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        if (nums.empty()) return {};

        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;

        for (int i=n-1; i>=0; i--) {
            if (i+1<n && nums[i] == nums[i+1]) continue;

            int left = 0;
            int right = i-1;
            int target = -nums[i];

            while (left < right) {
                int twoSum = nums[left]+nums[right];
                if (twoSum < target) {
                    left++;
                } else if (twoSum > target) {
                    right--;
                } else {
                    // find a valid triplet
                    res.push_back( {nums[i], nums[left], nums[right]} );
                    left++;
                    right--;
                    while (left<right && nums[left] == nums[left-1]) left++;
                    while (left<right && nums[right] == nums[right+1]) right--;
                }
            }
        }
        return res;
    }
};