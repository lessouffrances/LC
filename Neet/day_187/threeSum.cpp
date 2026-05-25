class Solution 
{
    public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        if (nums.empty()) return {};
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (int i=0; i<n-2; i++) {
            if (i>0 && nums[i] == nums[i-1]) continue;

            int diff = -nums[i];
            int left = i+1;
            int right = n-1;
            while (left < right) {
                int twoSum = nums[left]+nums[right];
                if (twoSum < diff) {
                    left++;
                } else if (twoSum > diff) {
                    right--;
                } else {
                    // find a valid trip
                    res.push_back( { nums[i], nums[left], nums[right] } );
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