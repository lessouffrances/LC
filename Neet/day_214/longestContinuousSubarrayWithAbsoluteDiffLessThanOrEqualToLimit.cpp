class Solution 
{
    public:
    int longestSubarray(vector<int>& nums, int limit) 
    {
        deque<int> maxDq; // front is the max
        deque<int> minDq; // front is the min

        int n = nums.size(); 
        int left = 0;
        int maxLen = INT_MIN;
        for (int right=0; right<n; right++) {
            // maintain maxDq
            while (!maxDq.empty() && nums[right] > nums[maxDq.back()]) {
                maxDq.pop_back();
            }
            maxDq.push_back(right);

            // maintain minDq
            while (!minDq.empty() && nums[right] < nums[minDq.back()]) {
                minDq.pop_back();
            }
            minDq.push_back(right);

            // update maxLen
            // shrink window when max-min > limit
            while (nums[maxDq.front()] - nums[minDq.front()] > limit) {
                left++;
                if (maxDq.front() < left) maxDq.pop_front();
                if (minDq.front() < left) minDq.pop_front();
            }
            maxLen = max(maxLen, right-left+1);
        }
        return maxLen;
    }
};