class Solution 
{
    public:
    int longestSubarray(vector<int>& nums, int limit) 
    {
        deque<int> maxDq; // decrease, front is max
        deque<int> minDq; // increase, front is min

        int left = 0, maxLen = 0;
        int n = nums.size();
        for (int right=0; right<n; right++) {
            // maintain maxDq
            while (!maxDq.empty() && nums[maxDq.back()] <= nums[right]) {
                maxDq.pop_back();
            }
            maxDq.push_back(right);
            // maintain minDq
            while (!minDq.empty() && nums[minDq.back()] >= nums[right]) {
                minDq.pop_back();
            }
            minDq.push_back(right);
            // shrink window if max - min > limit
            while (nums[maxDq.front()]-nums[minDq.front()] > limit) {
                left++;
                if (maxDq.front() < left) maxDq.pop_front();
                if (minDq.front() < left) minDq.pop_front();
            }
            maxLen = max(maxLen, right-left+1);
        } 
        
        return maxLen;
    }
};
