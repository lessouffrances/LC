class Solution 
{
    public:
    int countGoodSubarraySum(vector<int>& nums, int k) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();

        unordered_map<int, vector<int>> remainderToStartIdxes; // {remainder : idx}
        int sum = 0;
        int res = 0;
        for (int i=0; i<n; i++) {
            sum += nums[i];
            int remainder = sum % k;
            if (remainderToStartIdxes.count(remainder)) {
                for (int idx : remainderToStartIdxes[remainder]) {
                    if (i - idx >= 2) {
                        res++;
                    }
                }
            }
            remainderToStartIdxes[remainder].push_back(i);
        }
        return res;
    }
};