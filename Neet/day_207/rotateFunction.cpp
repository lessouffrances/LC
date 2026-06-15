// Intuition: when you rotate by 1, every element's index increases by 1 (contributing +sum), 
// except nums[n-1] which wraps to index 0 (losing n * nums[n-1] contribution).

class Solution 
{
    public:
    int maxRotateFunction(vector<int>& nums) 
    {

        int n = nums.size();
        long long sum = 0, F = 0;
        
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            F += i * nums[i];  // F(0)
        }
        
        long long maxRes = F;
        for (int k = 1; k < n; k++) {
            F = F + sum - (long long)n * nums[n-k];
            maxRes = max(maxRes, F);
        }
        return maxRes;
    }
};