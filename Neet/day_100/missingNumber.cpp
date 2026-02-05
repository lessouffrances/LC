










class Solution 
{
    public:
    int missingNumber(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();

        int actualSum = 0;
        int expSum = (0 + n) * (n+1) / 2;

        for (int num : nums) {
            actualSum += num;
        }
        return expSum - actualSum;
    }
};