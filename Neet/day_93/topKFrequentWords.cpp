class Solution 
{
    public:
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        if (words.empty()) return {};

        unordered_map<string, int> freq;
        for (auto& word : words) {
            freq[word]++;
        }

        auto comp = [](const auto& a, const auto& b){
            if (a.first != b.first) {
                return a.first < b.first;
            }
            return a.second > b.second; // lower lexi on top
        };

        // higher freq on top
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comp)> pq{comp};

        for (auto& [word, count] : freq) {
            pq.push( {count, word} );
        }

        vector<string> res;
        while (!pq.empty() && k > 0) {
            res.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return res;
    }
};