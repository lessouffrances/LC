

// Time: O(N + M logM), where M is the number of unique numbers
// N for building the freq, and M logM for pushing all {count, num} pairs onto pq
// Space: O(N), where N is the size of the input
class Solution 
{
    public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        // build freq
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // higher freq on top
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;

        // push all {num, count} to pq
        for (auto& [num, count] : freq) {
            pq.push( {count, num} );
        }

        int K = k;
        vector<int> res;
        while (K > 0 && !pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
            K--;
        }
        return res;
    }
};