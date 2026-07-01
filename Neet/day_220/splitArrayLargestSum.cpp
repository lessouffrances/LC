

class Solution 
{
    public:
    int splitArray(vector<int>& nums, int k) 
    {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);

        while (left < right) {
            int mid = left + (right-left)/2;
            if (canSplitIntoKChunksWithThisLimit(nums, k, mid)) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return left;
    }

    private:
    bool canSplitIntoKChunksWithThisLimit(vector<int>& nums, int k, int limit)
    {
        int numOfChunks = 1;
        int currSum = 0;
        for (int i=0; i<nums.size(); i++) {
            currSum += nums[i];
            if (currSum > limit) {
                currSum = nums[i];
                numOfChunks++;
            }
        }
        return numOfChunks <= k;
    }
};