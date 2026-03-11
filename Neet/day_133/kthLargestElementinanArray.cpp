class Solution 
{
    public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        if (nums.empty()) return 0;
        priority_queue<int, vector<int>, less<int>> pq; //minHeap

        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};