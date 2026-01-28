
// sum[0...i] % k = r
// sum[0...j] % k = r  (where j > i)
// Then: (sum[0...j] - sum[0...i]) % k = 0

class Solution 
{
    public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        if (nums.empty()) return false;

        int n = nums.size();
        unordered_map<int, int> remainderToIdx; // { remainder : startIdx }
        remainderToIdx[0] = -1; 

        int sum = 0;
        for (int i=0; i<n; i++) {
            sum += nums[i];
            int remainder = sum % k;
            if (remainderToIdx.count(remainder)) {
                if (i - remainderToIdx[remainder] >= 2) {
                    return true;
                }
            } else {
                remainderToIdx[remainder] = i;
            }
        }
        return false;
    }
};