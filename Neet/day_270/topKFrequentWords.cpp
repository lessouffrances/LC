class Solution 
{
    public:
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        if (words.empty() || words.size() < k) return {};
        
        // the format for a and b are {count, string}
        auto comp = [](const auto& a, const auto& b) {
            if (a.first != b.first) {
                return a.first > b.first;
            }
            return a < b; // lexi order
        };

        // minHeap based on freq
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comp)> pq{comp};

        unordered_map<string, int> freq;
        for (auto& w : words) freq[w]++;
        for (auto& [w, count] : freq) {
            pq.push( {count, w} );
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<string> res;
        while (!pq.empty()) {
            auto [count, w] = pq.top(); pq.pop();
            res.push_back(w);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};