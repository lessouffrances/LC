



// Time: O(N ^ 2)
// Space: O(1)

class Solution 
{
    public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        if (nums.empty()) return {};
        int n = nums.size();

        // sort for skipping duplicates
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        for (int i=0; i<n; i++) {
            if (i>0 && nums[i] == nums[i-1]) continue;
            int diff = -nums[i];
            int left = i+1, right = n-1;

            while (left < right) {
                int sum = nums[left]+nums[right];

                if (sum > diff) {
                    right--;
                } else if (sum < diff) {
                    left++;
                } else {
                    // find a triplet
                    res.push_back( {nums[i], nums[left], nums[right]} );

                    // skip
                    while (left<right && nums[left] == nums[left+1]) left++;
                    while (left<right && nums[right] == nums[right-1]) right--;
                    left++;
                    right--;
                }
            }
        }
        return res;
    }
};