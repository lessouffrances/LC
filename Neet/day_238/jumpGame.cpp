class Solution 
{
    public:
    // nums = [2,3,1,1,4]
    // nums = [3,2,1,0,4]
    bool canJump(vector<int>& nums) 
    {
        if (nums.empty()) return false;

        int n = nums.size();
        int maxReach = 0;
        for (int i=0; i<n; i++) {
            if (i > maxReach) return false;
            maxReach = max(i + nums[i], maxReach);
            if (maxReach >= n-1) return true;
        }
        return false;
    }
};