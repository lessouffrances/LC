class Solution 
{
    public:
    int jump(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();
        
        int farthest = 0, currEnd = 0, jumps = 0;
        for (int i=0; i<n-1; i++) {
            farthest = max(farthest, i+nums[i]);
            if (i == currEnd) {
                jumps++;
                currEnd = farthest;
            }
        }
        return jumps;
    }
};