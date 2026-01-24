class Solution 
{
    public:
    int longestSubarray(vector<int>& nums, int k)
    {
        if (nums.empty()) return 0;

        int left = 0;
        int maxNum = *max_element(nums.begin(), nums.end());
        vector<int>windowCounter(maxNum+1, 0);
        int n = nums.size();

        int dupCount = 0;
        int maxLen = INT_MIN;
        for (int right=0; right<n; right++) {
            windowCounter[nums[right]]++;
            if (windowCounter[nums[right]] == 2) {
                dupCount++;
            }

            while (dupCount > k) {
                windowCounter[nums[left]]--;
                if (windowCounter[nums[left]] == 1) {
                    dupCount--;
                }
                left++;
            }

            maxLen = max(maxLen, right-left+1);
        }
        
        return maxLen;
    }
};