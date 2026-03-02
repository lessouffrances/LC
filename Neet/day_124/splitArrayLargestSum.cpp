class Solution 
{
    public:
    int splitArray(vector<int>& nums, int k) 
    {
        // the two ends of the binary search
        long lo = *max_element(nums.begin(), nums.end());
        long hi = accumulate(nums.begin(), nums.end(), 0L);

        while (lo < hi) {
            long mid = lo + (hi - lo) / 2;
            if (canSplit(nums, k, mid)) {
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        return lo;
    }
    private:
    bool canSplit(vector<int>& nums, int k, long limit)
    {
        int numOfSubarrays = 1;
        long currSum = 0;
        for (int num : nums) {
            if (currSum + num > limit) {
                numOfSubarrays++;
                currSum = num; // reset
                if  (numOfSubarrays > k) return false;
            } else {
                currSum += num;
            }
        }
        return true;
    }
};
