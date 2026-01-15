class Solution 
{
    public:
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        if (words.empty()) return {};

        // build freq map
        unordered_map<string, int> freq;
        for (auto& word : words) {
            freq[word]++;
        }

        // pq puts the highest freq on top, and higher lexicographical order on top
        auto comp = [](const pair<int, string>& a, const pair<int, string>& b){
            if (a.first != b.first) {
                return a.first < b.first; // higher freq on top
            }
            return a.second > b.second;
        };

        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comp)> pq{comp};

        // push to the pq
        for (auto& [word, count] : freq) {
            pq.push( {count, word} );
        }

        vector<string> res;
        while (k > 0 && !pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return res;
    }
};