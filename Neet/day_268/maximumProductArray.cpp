class Solution 
{
    public:
    int maxProduct(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();

        int res = 0;
        int currMax = nums[0];
        int currMin = nums[0];

        for (int i=1; i<n; i++) {
            int tempMax = currMax;
            currMax = max( {nums[i], nums[i]*tempMax, nums[i]*currMin} );
            currMin = max( {nums[i], nums[i]*tempMax, nums[i]*currMin} );
            res = max(currMax, res);
        }
        return res;
    }
};