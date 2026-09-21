class Solution 
{
    public:
    int longestSubarray(vector<int>& nums, int limit) 
    {
        deque<int> maxDq;  // front the idx of the max
        deque<int> minDq; // front the idx of the min

        int n = nums.size();
        int left = 0;
        int maxLen = INT_MIN;

        // maintain a sliding window
        for (int right=0; right<n; right++) {
            // maintain maxDq
            // is some element is larger than the back, 
            // continue to pop back and push it
            while (!maxDq.empty() && nums[right] > numns[maxDq.back()]) {
                maxDq.pop_back();
            }
            maxDq.push_back(right);

            // maintain minDq
            while (!minDq.empty() && nums[right] < nums[minDq.back()]) {
                minDq.pop_back();
            }
            minDq.push_back(right);

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