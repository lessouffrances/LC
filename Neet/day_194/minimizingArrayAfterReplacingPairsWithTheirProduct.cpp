class Solution 
{
    public:
    int minArrayLength(vector<int>& nums, int k) 
    {
        if (nums.empty()) return 0;

        // if there is a 0 somewhere, 
        // the entire array will become 0
        for (int num : nums) {
            if (num == 0) return 1;
        }

        int count = 1;
        long long product = nums[0];
        for (int i=1; i<nums.size(); i++) {
           if (product * nums[i] <= k) {
                product *= nums[i];
            } else {
                product = nums[i];
                count++;
            }
        }
        return count;
    }
};