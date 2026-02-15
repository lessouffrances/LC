class Solution 
{
    public:
    string frequencySort(string s) 
    {
        if (s.length() == 0) return "";
        unordered_map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }

        auto comp = [](const auto& a, const auto& b ){
            return a.second < b.second; // higher freq on top
        };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(comp)> pq{comp};

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