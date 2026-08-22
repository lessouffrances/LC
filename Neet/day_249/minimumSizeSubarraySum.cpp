class Solution 
{
    public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        if (nums.empty()) return 0;

        int n = nums.size();
        int minLen = INT_MAX;
        int left = 0;
        int currSum = 0;
        for (int right=0; right<n; right++) {
            currSum += nums[right];

            // valid windows
            while (currSum >= target) {
                minLen = min(minLen, right-left+1);
                currSum -= nums[left];
                left++;
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};