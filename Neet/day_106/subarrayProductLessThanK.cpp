class Solution 
{
    public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
        if (nums.empty()) return 0;
        if (k <= 1) return 0;

        int n = nums.size();
        int left = 0;
        int currProduct = 1;
        int count = 0;
        for (int right=0; right<n; right++) {
            currProduct *= nums[right];

            while (currProduct >= k) {
                currProduct /= nums[left];
                left++;
            }

            count += right - left + 1;
        }
        return count;
    }
};