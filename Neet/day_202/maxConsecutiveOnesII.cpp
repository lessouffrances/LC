class Solution 
{
    public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();
        int windowCounterOfZeroes = 0;

        int left = 0;
        int maxLen = 0;
        for (int right=0; right<n; right++) {
            if (nums[right] == 0) windowCounterOfZeroes++;
            while (windowCounterOfZeroes > 1) {
                if (nums[left] == 0) {
                    windowCounterOfZeroes--;
                }
                left++;
            }

            maxLen = max(maxLen, right-left+1);
        }
        return maxLen;
    }
};