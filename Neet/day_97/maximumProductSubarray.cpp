class Solution 
{
    public:
    int maxProduct(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();

        int res = nums[0];
        int currMin = nums[0], currMax = nums[0];

        for (int i=1; i<n; i++) {
            int temp = currMax;
            currMax = max( {nums[i], temp * nums[i], currMin * nums[i]} );
            currMin = min( {nums[i], temp * nums[i], currMin * nums[i]} );
            res = max(currMax, res);
        }
        return res;
    }
};