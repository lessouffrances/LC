class Solution 
{
    public:
    int firstMissingPositive(vector<int>& nums) 
    {
        int n = nums.size();
        // the first missing positive must be in the range [1, n+1]
        for (int i=0; i<n; i++) {
            if (nums[i] <= 0 || nums[i] >= n+1) {
                nums[i] = n+1;
            }
        }

        for (int i=0; i<n; i++) {
            // By the time you reach index i in this loop, 
            // nums[i] may have already been negated by an earlier iteration
            int num = abs(nums[i]);
            if (num <= n) {
                nums[num-1] = -abs(nums[num-1]);
            }
        }

        for (int i=0; i<n; i++) {
            if (nums[i] > 0) return i+1;
        }
        return n+1;
    }
};