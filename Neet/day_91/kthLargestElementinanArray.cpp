class Solution 
{
    public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        if (nums.empty()) return 0;
        priority_queue<int> pq;

        for (int num : nums) {
            pq.push(num);
        }

        while (!pq.empty() && k > 1) {
            pq.pop();
            k--;
        }

        return pq.top();
    }
};