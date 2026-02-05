





// dp1= [0,1           ]
// dp2=   [0,4           ]
// nums = [1,4,2,5,6,7,11]

class Solution 
{
    public:
    int rob(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        // pass one 0 -> n-2
        vector<int> dp1(n, 0);
        dp1[0] = 0;
        dp1[1] = nums[0];
        for (int i=2; i<n; i++) {
            // take
            int take = nums[i-1] + dp1[i-2];
            // skip
            int skip = dp1[i-1];
            dp1[i] = max(skip, take);
        }

        // pass two 1 -> n-1
        vector<int> dp2(n, 0);
        dp2[0] = 0;
        dp2[1] = nums[1];
        for (int i=2; i<n; i++) {
            // take
            int take = nums[i] + dp2[i-2];
            // skip
            int skip = dp2[i-1];
            dp2[i] = max(skip, take);
        }

        return max(dp1[n-1], dp2[n-1]);
    }
};