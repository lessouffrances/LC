class Solution 
{
    public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        if (nums.empty()) return 0;

        int currCount = 0;
        int maxCount = 0;

        for (int num : nums) {
            if (num == 1) {
                currCount += 1;
                maxCount = max(maxCount, currCount);
            } else {
                currCount = 0;
            }
        }
        return maxCount;
    }
};