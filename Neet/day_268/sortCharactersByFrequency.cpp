class Solution 
{
    public:
    string frequencySort(string s) 
    {
        if (s.length() == 0) return "";

        unordered_map<char, int> freq;
        for (char ch : s) freq[ch]++;

        // maxHeap of freq
        priority_queue<pair<int, char>, vector<pair<int, char>>, less<pair<int, char>>> pq;
        for (auto& [ch, count] : freq) {
            pq.push( {count, ch} );
        }

        string res = "";
        while (!pq.empty()) {
            res.append(pq.top().first, pq.top().second);
            pq.pop();
        }
        return res;
    }
};