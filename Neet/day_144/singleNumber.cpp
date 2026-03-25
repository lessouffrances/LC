

// Time: O(N)
// Space: O(N)

class Solution 
{
    public:
    int singleNumber(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        int n = nums.size();

        int res = nums[0];
        for (int i=1; i<n; i++) {
            res ^= nums[i];
        }
        return res;
    }
};