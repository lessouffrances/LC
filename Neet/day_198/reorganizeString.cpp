class Solution 
{
    public:
    string reorganizeString(string s) 
    {
        if (s.length() == 0) return "";
         // build freq
        unordered_map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }
        // with the most frequent char on top
        priority_queue<tuple<int, int, char>> maxHeap; // { count, releaseTime, char }
        // populate the pq
        for (auto& [ch, count] : freq) {
            maxHeap.push( {count, 0, ch} );
        }

        string res = "";
        int time = 0;
        queue<tuple<int, int, char>> q;
        while (!q.empty() || !maxHeap.empty()) {
            // see any chars can be released from hold
            while (!q.empty() && get<1>(q.front()) <= time) {
                maxHeap.push( q.front() );
                q.pop();
            }

            if (maxHeap.empty()) break;
            
            if (!maxHeap.empty()) {
                auto [count, releaseTime, ch] = maxHeap.top();
                res += ch;
                maxHeap.pop();
                if (count > 1) {
                    q.push( {count-1, time+2, ch} );
                }
            }
            time++;
        }

        if (!maxHeap.empty() || !q.empty()) return "";
        return res;
    }
};