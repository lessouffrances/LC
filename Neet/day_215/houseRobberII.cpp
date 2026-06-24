class Solution 
{
    public:
    int rob(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        int n = nums.size();

        // house from 0 -> n-1
        vector<int> dp1(n, 0);
        dp1[0] = 0;
        dp1[1] = nums[0];
        for (int i=2; i<n; i++) {
            int take = dp1[i-2]+nums[i-1];
            int skip = dp1[i-1];
            dp1[i] = max(take, skip);
        }

        // house from 1 -> n
        vector<int> dp2(n, 0);
        dp2[0] = 0;
        dp2[1] = nums[1];
        for (int i=2; i<n; i++) {
            int take = dp2[i-2]+nums[i];
            int skip = dp2[i-1];
            dp2[i] = max(take, skip);
        }
        return max(dp1[n-1], dp2[n-1]);
    }
};