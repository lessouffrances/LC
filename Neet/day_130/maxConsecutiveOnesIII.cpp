class Solution 
{
    public:
    int longestOnes(vector<int>& nums, int k) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();

        int windowCountOfZeroes = 0;
        int left = 0;
        int maxLen = 0;
        for (int right=0; right<n; right++) {
            if (nums[right] == 0) {
                windowCountOfZeroes++;
            }

            while (windowCountOfZeroes > k) {
                if (nums[left] == 0) {
                    windowCountOfZeroes--;
                }
                left++;
            }
            maxLen = max(maxLen, right-left+1);
        }

        return maxLen;
    }
};
        