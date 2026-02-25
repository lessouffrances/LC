class Solution 
{
    public:
    int firstMissingPositive(vector<int>& nums) 
    {
        if (nums.empty()) return 1;
        int n = nums.size();

        // find missing positives in range [1, n]
        for (int i=0; i<n; i++) {
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = n+1; // exclude the irrelevant num
            }
        }

        for (int i=0; i<n; i++) {
            int num = abs(nums[i]);
            // since all irrelevant numbers have been marked as n+1
            if (num <= n) {
                nums[num-1] = -abs(nums[num-1]); // if the num was seen, negate the number at index num
            }
        }

        // if we find a positive number, means that the index+1 was the missing positive
        for (int i=0; i<n; i++) {
            if (nums[i] > 0) {
                return i+1;
            }
        }
        return n+1;
    }
};