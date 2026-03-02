class Solution 
{
    public:
    int firstMissingPositive(vector<int>& nums) 
    {
        int n = nums.size();
        for (int i=0; i<n; i++) {
            // these are the irrelevent ones
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = n + 1;
            }
        }

        for (int i=0; i<n; i++) {
            int num = abs(nums[i]);
            if (num <= n) {
                nums[num-1] = -abs(nums[num-1]); // flip  
            }
        }

        for (int i=0; i<n; i++) {
            // because all the visited have been flipped
            if (nums[i] > 0) {
                return i+1; 
            }
        }
        // because every number 1 -> n is present
        return n+1; 
    }
};