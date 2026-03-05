class Solution 
{
    public:
    int splitArray(vector<int>& nums, int k) 
    {
        // the two ends of the binary search
        int left = *max_element(nums.begin(), nums.end());
        long right = accumulate(nums.begin(), nums.end(), 0);

        while (left < right) {
            long mid = left + (right-left)/2;
            if (canSplit(nums, k, mid)) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return left;
    }

    private:
    // can this array be split into k subarrays with subarray sum <= limit?
    bool canSplit(vector<int>& nums, int k, long limit)
    {
        int numOfSubarrays = 1;
        int currSum = 0;

        for (int num : nums) {
            // if about to exceed the limit
            if (currSum + num > limit) {
                // increment numOfSubarrays
                numOfSubarrays++;
                currSum = num; // reset
                if (numOfSubarrays > k) return false;
            } else {
                currSum += num;
            }
        }
        return true;
    }
};