class Solution 
{
    public:
    double findMaxAverage(vector<int>& nums, int k) 
    {
        if (k > nums.size()) return 0.0;
        int n = nums.size();

        int left = 0;
        int currSum = accumulate(nums.begin(), nums.begin()+k, 0);
        int maxSum = currSum;

        for (int right=k; right<n; right++) {
            currSum = currSum + nums[right] - nums[left];
            left++;
            maxSum = max(maxSum, currSum);
        }
        return (double)maxSum / k;
    }
};