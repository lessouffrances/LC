class Solution 
{
    public:
    int longestSubarray(vector<int>& nums) 
    {
        if (nums.empty()) return 0;

        int n = nums.size();
        int maxLen = 0;
        int left = 0;
        int windowCounterOfZeros = 0;
        
        for (int right=0; right<n; right++) {
            if (nums[right] == 0) {
                windowCounterOfZeros++;
            } 

            while (windowCounterOfZeros > 1) {
                if (nums[left] == 0) {
                    windowCounterOfZeros--;
                }
                left++;
            }
            maxLen = max(maxLen, right-left);
        }
        return maxLen;
    }
}; 