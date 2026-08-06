class Solution 
{
    public:
    int longestOnes(vector<int>& nums, int k) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();

        int left = 0;
        int countZeros = 0;
        int maxLen = INT_MIN;
        for (int right=0; right<n; right++) {
            if (nums[right] == 0) countZeros++;
            // invalid window
            while (countZeros > k) {
                if (nums[left] == 0) countZeros--;
                left++;
            }
            maxLen = max(maxLen, right-left+1);
        }

        return maxLen;
    }
};