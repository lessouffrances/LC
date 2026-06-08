


// nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
//         l
//           r
// sliding condition: if zeroCount > 2 in the current window, shrink left 
class Solution 
{
    public:
    int longestOnes(vector<int>& nums, int k) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();

        int left = 0;
        int windowZeroCount = 0;
        int maxLen = INT_MIN;
        for (int right=0; right<n; right++) {
            if (nums[right] == 0) {
                windowZeroCount++;
            }

            while (windowZeroCount > k) {
                if (nums[left] == 0) {
                    windowZeroCount--;
                }
                left++;
            }

            maxLen = max(maxLen, right-left+1);
        }
        return maxLen;
    }
};