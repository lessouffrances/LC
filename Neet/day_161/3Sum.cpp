


// Time: O(N ^ 2)
// Space: O(N)

class Solution 
{
    public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        if (nums.empty()) return {};
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        
        // choose each num as the first in the triplet
        for (int i=0; i<n; i++) {
            if (i>0 && nums[i] == nums[i-1]) continue;
            // then we need to make this twoSum using 2-pointer technique
            int target = -nums[i];
            int left = i+1, right = nums.size()-1;
            while (left < right) {
                int twoSum = nums[left]+nums[right];
                if (twoSum < target) {
                    left++;
                } else if (twoSum > target) {
                    right--;
                } else {
                    // find a valid triplet
                    vector<int> triplet = {nums[left], nums[right], nums[i]};
                    res.push_back(triplet);
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