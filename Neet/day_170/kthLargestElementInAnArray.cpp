class Solution 
{
    public:
    // the k-th Largest == the (size-k)-th Smallest
    // nums = [3,2,1,5,6,4], k = 2, exp = 5
    // sorted = [1,2,3,4,5,6]
    int findKthLargest(vector<int>& nums, int k) 
    {
        if (nums.empty()) return -1;

        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int num : nums) {
            minHeap.push(num);
        }

        int timeToPop = nums.size()-k;
        while (timeToPop > 0) {
            minHeap.pop();
            timeToPop--;
        }

        return minHeap.top();
    }
};