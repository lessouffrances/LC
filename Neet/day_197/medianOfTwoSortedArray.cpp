class Solution 
{
    public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        priority_queue<int> maxHeap;
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());

        for (int num : nums1) {
            maxHeap.push(num);
            minHeap.push(maxHeap.top());
            maxHeap.pop();

            if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
        if (maxHeap.size() > minHeap.size()) return maxHeap.top();
        return (double) (minHeap.top()+maxHeap.top()) / 2;
    }
};