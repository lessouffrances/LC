








// sum(subarray[0, i]) % k == sum(subarray[0, j]) % k => sum(subarray[i, j]) % k == 0

class Solution 
{
    public:
    bool checkSubarraySum(vector<int>& nums, int k)
    {
        if (nums.empty()) return false;
        int n = nums.size();

        unordered_map<int, int> remainderToIdx; // { remainder : idx }
        remainder[0] = -1; 
        // for case that the good subarray is founded at 1 and the remainder is 0, make 1 -(-1) >= 2w work!

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