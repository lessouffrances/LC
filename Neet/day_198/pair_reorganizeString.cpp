class Solution 
{
    public:
    string reorganizeString(string s) 
    {
        if (s.length() == 0) return "";

        // build freqS
        unordered_map<char, int> freqS;
        for (char ch : s) {
            freqS[ch]++;
        }

        priority_queue<pair<int, char>> pq; // { count, char }
        for (auto& [ch, count] : freqS) {
            pq.push({count, ch});
        }

        string res = "";
        while (pq.size() >= 2) {
            auto [count1, ch1] = pq.top();
            pq.pop();
            auto [count2, ch2] = pq.top();
            pq.pop();

            res += ch1;
            res += ch2;
            
            if (count1 > 1) {
                pq.push( {count1-1, ch1} );
            }
            if (count2 > 1) {
                pq.push( {count2-1, ch2} );
            }
        }

        if (!pq.empty()) {
            auto [count, ch] = pq.top();
            if (count > 1) return "";
            res += ch;
        }
        return res;
    }
};