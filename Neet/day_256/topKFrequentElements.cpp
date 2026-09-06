class Solution 
{
    public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        if (nums.empty()) return {};

        unordered_map<int, int> freq;
        for (int num : nums) freq[num]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (auto& [num, count] : freq) {
            minHeap.push( {count, num} );
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<int> res;
        while (!minHeap.empty()) {
            auto [count, num] = minHeap.top();
            minHeap.pop();
            res.push_back(num);
        }
        
        return res;
    }
};