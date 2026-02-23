class KthLargest 
{
    public:
    KthLargest(int k, vector<int>& nums) 
    {
        for (int num : nums) {
            pq.push(num);
        }
        K = k;
    }
    int add(int val) 
    {
        pq.push(val);
        while (pq.size() > K) {
            pq.pop();
        }
        return pq.top();
    }
    private:
    int K;
    priority_queue<int, vector<int>, greater<int>> pq; // minHeap
};
    
   