class Solution 
{
    public:
    // essentially find the min1 and min2 in the array
    // cannot change the cost for the first subarray
    int minimumCost(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();

        int min1 = INT_MAX;
        int min2 = INT_MAX;
        for (int i=1; i<n; i++) {
            if (nums[i] < min1) {
                min2 = min1;
                min1 = nums[i];
            } else if (nums[i] < min2) {
                min2 = nums[i];
            }
        }
        return nums[0]+min1+min2;
    }
};