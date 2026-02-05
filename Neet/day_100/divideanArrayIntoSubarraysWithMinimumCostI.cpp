class Solution 
{
    public:
    int minimumCost(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();
        int total = nums[0];

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

        return total + min1 + min2;
    }
};