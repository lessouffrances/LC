




//         0  1  2  3  4 5
// nums = [1,12,-5,-6,50,3], k = 4
// 

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

        for (int right=k; right < n; right++) {
            currSum = currSum + nums[right] - nums[left];
            left++;
            maxSum = max(currSum, maxSum);
        }
        return (double)maxSum / k;
    }
};