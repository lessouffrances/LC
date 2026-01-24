class Solution 
{
    public:
    int longestSubarray(vector<int>& nums, int k) 
    {
        if (nums.empty()) return 0;
        int n = nums.size(); // n=7
        int left = 0; 
        int maxLen = INT_MIN;
        unordered_map<int, int> windowCounter;
        int dupCount = 0;

        for (int right=0; right<n; right++) { 
            windowCounter[nums[right]]++;

            if (windowCounter[nums[right]] == 2) dupCount++;

            while (count > k) {
                windowCounter[nums[left]]--;  
                if (windowCounter[nums[left]] == 0) {
                    windowCounter.erase(nums[left]); 
                }
                if (windowCounter[nums[left]] == 1) dupCount--;

                left++;
              
            }
            maxLen = max(maxLen, (right-left+1)); 
        }
        return maxLen;
    }
};