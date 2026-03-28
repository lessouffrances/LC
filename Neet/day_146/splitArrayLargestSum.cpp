


class Solution 
{
    public:
    // key word: minimized largest sum => binary search
    int splitArray(vector<int>& nums, int k) 
    {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);

        while (left < right) {
            int mid = left + (right-left) / 2;
            if (canSplit(nums, k, mid)) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return left;
    }

    private:
    bool canSplit(vector<int>& nums, int k, int limit)
    {
        int numOfSubarrays = 0;
        int currSum = 0;

        for (int num : nums) {
            currSum += num;
            if (currSum > limit) {
                currSum = 0;
                numOfSubarrays++;
                if (numOfSubarrays > k) return false;
            }
        }
        return true;
    }
};