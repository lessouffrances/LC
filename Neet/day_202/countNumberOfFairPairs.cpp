// lower <= nums[i] + nums[j] <= upper
// use lower_bound to find the lo idx: lower-nums[i]
// use upper_bound to find the hi idx: upper-nums[i]
class Solution 
{
    public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) 
    {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        long long res = 0;
        for (int i=0; i<n; i++) {
            int lo = lower_bound(nums.begin()+i+1, nums.end(), upper-nums[i]) - nums.begin();
            int hi = upper_bound(nums.begin()+i+1, nums.end(), lower-nums[i]) - nums.begin();
            res += (hi-lo);
        }
        return res;
    }
};