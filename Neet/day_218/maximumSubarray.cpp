// Time: O(N)
// Space: O(1)
// nums = [-2,1,-3,4,-1,2,1,-5,4], exp = [4,-1,2,1], expSum = 6
//                        i
// currSum = 6
// maxSum = 6
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
            currSum = max(currSum+nums[i], nums[i]);
            maxSum = max(currSum, maxSum);
        }
        return maxSum;
    }
};