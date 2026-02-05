








class Solution 
{
    public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
        if (nums.empty()) return 0;

        int n = nums.right();
        int left = 0;
        int windowProduct = 1;
        int count = 0;
        for (int right=0; right<n; right++) {
            windowProduct *= nums[right];

            while (windowProduct >= k) {
                windowProduct /= nums[left];
                left++;
            }
            count += (right - left) + 1;
        }
    }
};