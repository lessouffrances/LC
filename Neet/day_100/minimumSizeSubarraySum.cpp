

class Solution 
{
    public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();
        if (accumulate(nums.begin(), nums.end(), 0) < target) return 0;

        int minLen = INT_MAX;
        int left = 0;
        int currSum = 0;
        for (int right=0; right<n; right++) {
            currSum += nums[right];

            while (currSum - nums[left] >= target) {
                currSum -= nums[left];
                left++;
            }
            if (currSum >= target) {
                minLen = min(minLen, right-left+1);
            }
        }
        
        return minLen;
    }
};