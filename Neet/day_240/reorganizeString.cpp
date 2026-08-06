

class Solution 
{
    public:
    string reorganizeString(string s) 
    {
        // count freq
        unordered_map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }

        // greedy, start with the char with the hightest freq
        priority_queue<pair<int, char>> pq;
        // push all onto the pq
        for (auto& [ch, count] : freq) {
            pq.push( {count, ch} );
        }

        string res = "";
        while (pq.size() >= 2) {
            auto [count1, ch1] = pq.top();
            pq.pop();
            auto [count2, ch2] = pq.top();
            pq.pop();

            res += ch1;
            res += ch2;

            if (count1 > 1) pq.push( {count1-1, ch1} );
            if (count2 > 1) pq.push( {count2-1, ch2} );
        }

        // we hope, there's only one char left
        if (!pq.empty() && pq.top().first > 1) return "";
        if (!pq.empty()) {
            res += pq.top().second;
            pq.pop();
        }
        
        return res;
    }
};