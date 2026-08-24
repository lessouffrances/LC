class Solution 
{
    public:
    int longestOnes(vector<int>& nums, int k) 
    {
        if (nums.empty()) return 0;

        int n = nums.size();
        int left = 0;
        int windowCounterOfZero = 0;
        int maxLen = 0;
        for (int right=0; right<n; right++) {
            if (nums[right] == 0) windowCounterOfZero++;

            // invalid windows
            while (windowCounterOfZero > k) {
                if (nums[left] == 0) windowCounterOfZero--;
                left++;
            }
            maxLen = max(maxLen, right-left+1);
        }
        return maxLen;
    }
};