class Solution 
{
    public:
    string frequencySort(string s) 
    {
        // build freq
        unordered_map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }

        auto comp = [](const auto& a, const auto& b) {
            return a.second < b.second; // high freq on top
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq{comp};

        for (auto& [ch, count] : freq) {
            pq.push( {ch, count} );
        }

        string res = "";
        while (!pq.empty()) {
            auto [ch, count] = pq.top();
            pq.pop();
            res.append(count, ch);
        }
        return res;
    }
};