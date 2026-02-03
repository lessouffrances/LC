class Solution 
{
    public:
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        // build freq
        unordered_map<string, int> freq;
        for (auto& word : words) {
            freq[word]++;
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, Comp> pq;
        for (auto& [word, count] : freq) {
            pq.push( {count, word} );
        }

        vector<string> res;
        for (int i=0; i<k; i++) {
            if (!pq.empty()) {
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }
    private:
    struct Comp
    {
        bool operator()(const auto& a, const auto& b) {
            if (a.first != b.first) {
                return a.first < b.first;
            }
            return a.second > b.second;
        }
    };
};
