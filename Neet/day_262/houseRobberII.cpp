class Solution 
{
    public:
    int rob(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        // one pass
        // consider 0 -> n-2
        vector<int> dp1(n, INT_MIN);
        dp1[0] = 0;
        dp1[1] = nums[0]; // base case
        for (int i=2; i<n; i++) {
            int take = nums[i-1] + dp1[i-2];
            int skip = dp1[i-1];
            dp1[i] = max(take, skip);
        }

        // second pass
        // consider 1 -> n-1
        vector<int> dp2(n, INT_MIN);
        dp2[0] = 0;
        dp2[1] = nums[1]; // base case
        for (int i=2; i<n; i++) {
            int take = nums[i] + dp2[i-2];
            int skip = dp2[i-1];
            dp2[i] = max(take, skip);
        }

        return max(dp1[n-1], dp2[n-1]);
    }
};