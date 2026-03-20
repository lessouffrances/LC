

// Time: O(N)
// Space: O(1)

class Solution 
{
    public:
    int longestOnes(vector<int>& nums, int k) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();

        int left = 0;
        int windowZeros = 0;
        int maxLen = 0;
        for (int right=0; right<n; right++) {
            if (nums[right] == 0) {
                windowZeros++;
            }
            while (windowZeros > k) {
                if (nums[left] == 0) {
                    windowZeros--;
                }
                left++;
            }
            maxLen = max(maxLen, right-left+1); 
        }
        return maxLen;
    }
};