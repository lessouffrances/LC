class Solution 
{
    public:
    int firstMissingPositive(vector<int>& nums) 
    {
        if (nums.empty()) return 0;

        int n = nums.size();
        // set irrelevant ones
        for (int i=0; i<n; i++) {
            if (nums[i]<=0 || nums[i]>n) {
                nums[i] = n+1;
            }
        }

        for (int i=0; i<n; i++) {
            int num = abs(nums[i]);
            if (num <= n) {
                nums[i] = -abs(nums[i]);
            }
        }

        for (int i=0; i<n; i++) {
            if (nums[i] > 0) return i+1;
        }
        return n+1;
    }
};