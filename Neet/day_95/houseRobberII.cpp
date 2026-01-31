class Solution 
{
    public:
    int rob(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();
        if (n == 1) return nums[0];

        // 0 -> n-2 houses
        vector<int>passOne(n-1, 0);
        passOne[0] = nums[0];
        for (int i=1; i<n-1; i++) {
            int take = (i-2) >= 0 ? nums[i] + passOne[i-2] : nums[i];
            int skip = (i-1) >= 0 ? passOne[i-1] : 0;

            passOne[i] = max(take, skip);
        }

        // 1 -> n-1 houses
        vector<int>passTwo(n-1, 0);
        passTwo[0] = nums[1];
        for (int i=1; i<n-1; i++) {
            int take = (i-2) >= 0 ? nums[i+1] + passTwo[i-2] : nums[i+1];
            int skip = (i-1) >= 0 ? passTwo[i-1] : 0;

            passTwo[i] = max(take, skip);
        }; 
        
        return max(passOne[n-2], passTwo[n-2]);
    }
};