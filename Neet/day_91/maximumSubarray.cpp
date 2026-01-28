class Solution 
{
    public:
    int maxSubArray(vector<int>& nums) 
    {
        if (nums.empty()) return 0;

        int n = nums.size();
        int maxSum = nums[0], currSum = nums[0];
        for (int i=1; i<n; i++) {
            currSum = max(currSum+nums[i], nums[i]);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};