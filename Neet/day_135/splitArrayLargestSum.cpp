

// Time: O(N log S), where S is the dist from left to right
// Space: O(1)
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
    // can this nums be split into k subarrays with sum <= limit?
    bool canSplit(vector<int>& nums, int k, int limit)
    {
        int numOfSubarrays = 1;
        int currSum = 0;

        // iteratively detect if can be split
        for (int num : nums) {
            if (currSum + num > limit) {
                currSum = num;
                numOfSubarrays++;
                if (numOfSubarrays > k) return false;
            } else {
                currSum += num;
            }
        }
        return true;
    }
};