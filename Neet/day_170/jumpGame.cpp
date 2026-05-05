
// T: O(N)
// S: O(1)

class Solution 
{
    public:
    // [2,3,1,1,4]
    bool canJump(vector<int>& nums) 
    {
        if (nums.empty()) return false;

        int maxReach = 0;
        int n = nums.size();
        for (int i=0; i<n; i++) {
            if (i > maxReach) return false;
            maxReach = max(i+nums[i], maxReach);
            if (maxReach >= n-1) return true;
        }
        return false;
    }
};