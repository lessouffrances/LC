class Solution 
{
    public:
    int jump(vector<int>& nums) 
    {
        if (nums.empty()) return 0;

        int farthestIdx = 0;
        int curr = 0;
        int res = 0;

        while (farthestIdx < n-1) {
            int nextFarthest = 0;
            for (int i=curr; i<=farthestIdx; i++) {
                nextFarthest = max(nextFarthest, i+nums[i]);
            }
            if (nextFarthest <= farthestIdx) return -1;
            curr = farthestIdx+1;
            res++;
        }
        return res;
    }
};