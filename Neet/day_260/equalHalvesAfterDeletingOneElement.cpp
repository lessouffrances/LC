class Solution
{
    public:
    bool equalHalves(vector<int>& nums)
    {
        if (nums.size() <= 2) return false;
        int n = nums.size();

        int total = 0;
        for (int num : nums) total += num;

        // try removing each element
        for (int i = 0; i < n; i++) {
            int remaining = total - nums[i];
            if (remaining % 2 != 0) continue;  // can't split an odd sum evenly

            int half = remaining / 2;
            int running = 0;

            // scan the remaining elements (skipping index i), looking for
            // a prefix that sums to exactly half
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                running += nums[j];
                if (running == half) return true;
                if (running > half) break;  
            }
        }

        return false;
    }
};