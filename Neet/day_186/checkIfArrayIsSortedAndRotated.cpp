class Solution 
{
    public:
    bool check(vector<int>& nums) 
    {
        if (nums.empty()) return false;

        int n = nums.size();
        int drops = 0;
        for (int i=0; i<n; i++) {
            if (nums[(i+1) % n] < nums[i]) drops++;
            if (drops > 1) return false;
        }
        return true;
    }
};