class KthLargest 
{
    public:
    KthLargest(int k, vector<int>& nums) 
    {
        K = k;
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) pq.pop();
        }
    }
    
    int add(int val) 
    {
        pq.push(val);
        if (pq.size() > K) pq.pop();
        return pq.top();
    }

    private:
    int K; 
    // a minHeap sized k, the top is the k-th largest
    priority_queue<int, vector<int>, greater<>> pq;
};
    
    