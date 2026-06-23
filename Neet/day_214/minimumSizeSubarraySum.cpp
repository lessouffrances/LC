class Solution 
{
    public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int n = nums.size();
        int left = 0;
        int currSum = 0;
        int minLen = INT_MAX;
        for (int right=0; right<n; right++) {
            currSum += nums[right];
            while (currSum >= target) {
                minLen = min(minLen, right-left+1);
                currSum -= nums[left];
                left++;
            }
        }
        return (minLen == INT_MAX) ? 0 : minLen;
    }
};