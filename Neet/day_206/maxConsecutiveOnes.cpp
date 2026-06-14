class Solution 
{
    public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        if (nums.empty()) return 0;

        int currLen = 0, maxLen = 0;
        for (int num : nums) {
            if (num == 1) {
                currLen++;
                maxLen = max(maxLen, currLen);
            } else {
                currLen = 0;
            }
        }
        return maxLen;
    }
};