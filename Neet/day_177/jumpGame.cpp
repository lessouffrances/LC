class Solution 
{
    public:
    bool canJump(vector<int>& nums) 
    {
        if (nums.empty()) return false;
        int n = nums.size();

        int maxReach = 0;
        for (int i=0; i<n; i++) {
            if (maxReach < i) return false;

            maxReach = max(maxReach, i+nums[i]);
            if (maxReach >= n-1) return true;
        }
        return false;
    }
};