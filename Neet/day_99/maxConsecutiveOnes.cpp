




//           i
// nums = [1,1,0,1,1,1]


class Solution 
{
    public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();
        int maxLen = 0;
        int left = 0, right = 0;

        while (right < n) {
            if (nums[right] == 1) {
                int currLen = 1;
                while (right+1 < n && nums[right] == nums[right+1]) {
                    right++;
                    currLen++;
                }
                maxLen = max(currLen, maxLen);
            }
            right++;
        }
    

        return maxLen;
    }
};