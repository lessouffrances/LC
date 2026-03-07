



// nums1 = [1,2,3,4,5,6]
// nums2 = [4,5,6]

// maxHeap = {1}
// minHeap = {}

class Solution 
{
    public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        // minHeap
        priority_queue<int, vector<int>, greater<int>> minHeap;
        // maxHeap
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
        // 2 cases, minHeap.size() == maxHeap.size()
        if (maxHeap.size() > minHeap.size()) return (double) maxHeap.top();
        return (double) (maxHeap.top()+minHeap.top()) / 2;
    }
};