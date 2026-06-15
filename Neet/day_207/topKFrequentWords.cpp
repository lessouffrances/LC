class Solution 
{
    public:
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        unordered_map<string, int> freq;
        for (auto& word : words) {
            freq[word]++;
        }

        // maxHeap based on count
        auto comp = [](const pair<int, string>& a, const pair<int, string>& b){
            if (a.first != b.first) {
                return a.first < b.first; // higher freq on top
            }
            return a.second > b.second; // smaller lexicographically on top
        };

        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comp)> pq(comp);
        for (auto& [w, count] : freq) {
            pq.push( {count, w} );
        }

        vector<string> res;
        while (!pq.empty() && k>0) {
            res.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return res;
    }
};