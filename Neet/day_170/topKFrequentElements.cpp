class Solution 
{
    public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        if (nums.empty()) return {};

        // build freq map
        unordered_map<int, int> freq; // { num, freq }
        int n = nums.size();
        for (int i=0; i<n; i++) {
            freq[nums[i]]++;
        }

        priority_queue<pair<int, int>, 
        vector<pair<int, int>>, 
        greater<pair<int, int>>> minHeap; // {count, num}

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