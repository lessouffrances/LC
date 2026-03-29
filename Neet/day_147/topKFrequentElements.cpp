


class Solution 
{
    public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        if (nums.empty() || k > nums.size()) return {};
        
        // build freq
        unordered_map<int, int> freq; 
        for (int num : nums) {
            freq[num]++;
        }

        // minHeap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (auto& [num, count] : freq) {
            pq.push( {count, num });
            if (pq.size() > k) {
                pq.pop();
            }
        } 

        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};