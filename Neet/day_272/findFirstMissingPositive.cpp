class Solution 
{
    public:
    int firstMissingPositive(vector<int>& nums) 
    {
        if (nums.empty()) return 1;
        int n = nums.size();

        // insight: the result can only be in the range [1, n+1]
        // n=5, [0,1,3,4,6], exp = 2

        for (int i=0; i<n; i++) {
            if (nums[i] > n || nums[i] <= 0) {
                nums[i] = n+1;
            }
        }

        for (int i=0; i<n; i++) {
            int num = abs(nums[i]);
            if (num <= n) {
                // flip 
                nums[num-1] = -abs(nums[num-1]);
            }
        }

        for (int i=0; i<n; i++) {
            if (nums[i] > 0) return i+1; 
        }
        return n+1;
    }
};