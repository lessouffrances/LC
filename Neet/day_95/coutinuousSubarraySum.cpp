








// sum(subarray[0, i]) % k == sum(subarray[0, j]) % k => sum(subarray[i, j]) % k == 0
// LC is to check if such a good subarray exist, now count the good subarray

class Solution 
{
    public:
    int countGoodSubarraySum(vector<int>& nums, int k)
    {
        if (nums.empty()) return 0;
        int n = nums.size();

        unordered_map<int, vector<int>> remainderToIdxes;
        remainderToIdxes[0] = { -1 };
        int currSum = 0;
        int count = 0;

        for (int i=0; i<n; i++) {
            currSum += nums[i];
            int remainder = currSum % k;

            if (remainderToIdxes.count(remainder)) {
                for (auto& idx : remainderToIdxes[remainder]) {
                    if (i - idx >= 2) count++;
                }
            } 

            remainderToIdxes[remainder].push_back(i);
        }

        return count;
    }
};