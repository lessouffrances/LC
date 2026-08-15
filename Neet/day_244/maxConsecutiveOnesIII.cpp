class Solution 
{
    public:
    int longestOnes(vector<int>& nums, int k) 
    {
        if (nums.empty()) return 0;

        int n = nums.size();
        int left = 0;
        int countOfZeros = 0;
        int maxLen = 0;
        for (int right=0; right<n; right++) {
            if (nums[right] == 0) countOfZeros++;

            // invalid window
            while (countOfZeros > k) {
                if (nums[left] == 0) countOfZeros--;
                left++;
            }
            maxLen = max(maxLen, right-left+1);
        }
        return maxLen;
    }
};