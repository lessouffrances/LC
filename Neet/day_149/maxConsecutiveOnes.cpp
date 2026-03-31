


// nums = [1,1,0,1,1,1]
//         r
class Solution 
{
    public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();

        int maxLen = 0;
        int right = 0;
        while (right < n) {
            if (nums[right] == 1) {
                int currLen = 0;
                while (right < n && nums[right] == 1) {
                    currLen++;
                    right++;
                }
                maxLen = max(maxLen, currLen);
            } else {
                right++;
            }
            
        }
        return maxLen;
    }
};