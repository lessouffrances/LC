class Solution 
{
    public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();
        // minHeap
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i=0; i<n; i++) {
            pq.push(nums[i]);
            if (pq.size() > k) pq.pop();
        }

        return pq.top();
    }
};