







// 7
// l,r
// [2, 3, 1, 2, 4, 3], exp = 2
// windowSum = 2
class Solution 
{
    public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();

        int left = 0;
        int windowSum = 0;
        int minLen = INT_MAX;
        for (int right=0; right<n; right++) {
            windowSum += nums[right];

            while (windowSum - nums[left] >= target) {
                windowSum -= nums[left];
                left++;
            }

            if (windowSum >= target) {
                minLen = min(minLen, right-left+1);
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};