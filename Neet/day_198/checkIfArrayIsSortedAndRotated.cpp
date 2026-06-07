// globally, there is only one drop

class Solution 
{
    public:
    bool check(vector<int>& nums) 
    {
        int n = nums.size();
        int drops = 0;
        for (int i=0; i<n; i++) {
            if (nums[(i+1) % n] < nums[i % n]) drops++;
        }
        return drops <= 1;
    }
};