class Solution 
{
    public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        if (nums.empty()) return false;
        int n = nums.size();

        unordered_map<int, int> remainderToIdx;
        remainderToIdx[0] = -1;
        int currSum = 0;
        for (int i=0; i<n; i++) {
            currSum += nums[i];
            int remainder = currSum % k;

            if (remainderToIdx.count(remainder)) {
                if (i-remainderToIdx[remainder] >= 2) return true;
            } else {
                remainderToIdx[remainder] = i;
            }
        }
        
        return false;
    }
};