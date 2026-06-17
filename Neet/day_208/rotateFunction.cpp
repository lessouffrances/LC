class Solution 
{
    public:
    int maxRotateFunction(vector<int>& nums) 
    {
        int n = nums.size();
        long long totalSum = 0;
        long long F = 0;
        for (int i=0; i<n; i++) {
            totalSum += nums[i];
            F += i * nums[i]; // F(0)
        }

        long long maxRes = F; // initiate maxRes with F
        for (int k=1; k<n; k++) {
            F = F + totalSum - (long long)n * nums[n-k];
            maxRes = max(maxRes, F);
            // Key Point:
            // how do we arrive at the "- n * nums[n-k]"
            // because the original (n-1) * nums[n-k] was subtracted,
            // and the original nums[n-k] wraps around to index 0
        }
        return maxRes;
    }
};