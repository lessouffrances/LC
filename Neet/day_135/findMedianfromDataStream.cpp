class MedianFinder 
{
    public:
    MedianFinder() {}
    void addNum(int num) 
    {
        // push to maxHeap first,
        // move from maxHeap to minHeap
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    double findMedian() 
    {
        // if maxHeap has one more element than minHeap as expected
        if (maxHeap.size() > minHeap.size()) return (double) maxHeap.top();
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
    private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
};
    
    