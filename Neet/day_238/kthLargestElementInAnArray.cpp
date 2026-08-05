class Solution 
{
    public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        if (nums.empty()) return;

        int n = nums.size();
        // init a minHeap
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i=0; i<n; i++) {
            pq.push(nums[i]);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};