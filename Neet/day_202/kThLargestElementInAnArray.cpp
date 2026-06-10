class Solution 
{
    public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        if (nums.empty()) return 0;

        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) minHeap.pop();
        } 
        return minHeap.top();
    }
};