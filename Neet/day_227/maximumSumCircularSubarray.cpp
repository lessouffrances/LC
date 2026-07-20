class Solution 
{
    public:
    int maxSubarraySumCircular(vector<int>& nums) 
    {
        if (nums.empty()) return 0;

        int currMax = nums[0], globalMax = nums[0];
        int currMin = nums[0], globalMin = nums[0];
        int totalSum = nums[0];

        for (int i=1; i<nums.size(); i++) {
            currMax = max(currMax+nums[i], nums[i]);
            globalMax = max(currMax, globalMax);

            currMin = min(currMin+nums[i], nums[i]);
            globalMin = min(currMin, globalMin);
            totalSum += nums[i];
        }

        return globalMax > 0 ? max(globalMax, totalSum-globalMin) : globalMax;
    }
};