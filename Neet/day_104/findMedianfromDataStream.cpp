




class MedianFinder 
{
    public:
    MedianFinder() {}
    
    void addNum(int num) 
    {
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
        if (maxHeap.size() > minHeap.size()) return (double)maxHeap.top();
        return (minHeap.top() + maxHeap.top()) / 2.0;
    }
    private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
};
    
    