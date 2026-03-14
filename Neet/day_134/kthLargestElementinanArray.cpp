

class Solution 
{
    public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        if (nums.empty() || k > nums.size()) return -1;
        
        // minHeap
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int num : nums) {
            pq.push(num);
            // kick out the min one
            if (pq.size() > k) {
                pq.pop();
            }
        }

        return pq.top();
    }
};