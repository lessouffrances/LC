class Solution 
{
    public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) 
    {
        int n = nums.size();
        long long count = 0;

        int windowStart = 0;
        int lastValidInRange = -1;
        for (int i=0; i<n; i++) {
            if (nums[i] > right) windowStart = i+1;
            if (nums[i] >= left && nums[i] <= right) lastValidInRange = i;
            if (lastValidInRange >= windowStart) {
                count += (lastValidInRange - windowStart + 1);
            }
        }
        return count;
    }
};