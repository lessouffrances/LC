





// Med =[1,1,5,5,5,4,3]
// DS = [1,5,6,7,2,4,3]
// maxHeap = 1 2 3 4  
// minHeap = 7 6 5  


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
        if (maxHeap.size() > minHeap.size()) return maxHeap.top();
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
    private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
};
    
    