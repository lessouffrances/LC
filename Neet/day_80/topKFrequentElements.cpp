class Solution 
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;

        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        };

        for (auto& [num, count] : freq) {
            pq.push( {count, num} );
        }

        vector<int> res;
        while (!pq.empty() && k > 0) {
            res.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return res;
    }
};