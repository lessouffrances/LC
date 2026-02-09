






class Solution 
{
    public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int m = nums1.size();
        int n = num2.size();

        for (int i=0; i<m+n; i++) {
            maxHeap.push(nums1[i]);
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }

        if (maxHeap.size() > minHeap.size())  return (double)maxHeap.top();
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};