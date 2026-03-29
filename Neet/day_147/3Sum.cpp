


// Time: O(N ^ 2)
// Space: O(1)
class Solution 
{
    public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        if (nums.empty()) return {};
        int n = nums.size();

        // for skipping duplicates
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        for (int i=0; i<n; i++) {
            if (i>0 && nums[i] == nums[i-1]) continue;
            int diff = -nums[i];

            // goal: find the twoSum equals diff
            // since it is sorted
            int left = i+1, right = n-1;
            while (left < right) {
                int twoSum = nums[left]+nums[right];

                if (twoSum > diff) {
                    right--;
                } else if (twoSum < diff) {
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