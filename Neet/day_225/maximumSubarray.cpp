class Solution 
{
    public:
    int maxSubArray(vector<int>& nums) 
    { 
        if (nums.empty()) return 0;
        int n = nums.size();
        int currSum = nums[0];
        int maxSum = nums[0];

        for (int i=1; i<n; i++) {
            currSum = max(nums[i], currSum);
            maxSum = max(currSum, maxSum);
        }
        return maxSum;
    }
};