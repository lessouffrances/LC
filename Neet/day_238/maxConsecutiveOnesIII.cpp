class Solution 
{
    public:
    int longestOnes(vector<int>& nums, int k) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();

        int left = 0;
        int countOne = 0;
        int maxLen = 0;
        for (int right=0; right<n; right++) {
            if (nums[right] == 1) countOne++;

            // invalid windows
            while ((right-left+1) - countOne > k) {
                if (nums[left] == 1) countOne--;
                left++;
            }
            maxLen = max(maxLen, right-left+1);
        }
        return maxLen;
    }
};