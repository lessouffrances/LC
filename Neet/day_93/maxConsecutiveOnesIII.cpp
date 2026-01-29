class Solution 
{
    public:
    int longestOnes(vector<int>& nums, int k) 
    {
        if (nums.empty()) return 0;

        int n = nums.size();
        int left = 0;
        int windowZeros = 0; 
        int maxLen = INT_MIN;

        for (int right = 0; right<n; right++) {
            if (nums[right] == 0) {
                windowZeros++;
            }

            while (windowZeros > k) {
                if (nums[left] == 0) {
                    windowZeros--;
                }
                left++;
            }
            maxLen = max(right - left + 1, maxLen);
        }
        return maxLen;
    }
};