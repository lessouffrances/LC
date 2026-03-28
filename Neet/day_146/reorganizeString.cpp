
// Time: O(N logM), where N is the length of s and M is the number of unique chars.
// Space: O(N)

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

        // tuple: { count, releaseTime, ch }
        priority_queue<tuple<int, int, char>, vector<tuple<int, int, char>>, less<tuple<int, int, char>>> pq;
        queue<tuple<int, int, char>> q;

        // populated pq
        for (auto& [ch, count] : freq) {
            pq.push( {count, 0, ch} );
        }

        int time = 0;
        string res = "";
        while (!pq.empty() || !q.empty()) {
            // release all the char that can be released from q
            // releaseTime <= time
            while (!q.empty() && get<1>(q.front()) <= time) {
                pq.push( q.front() );
                q.pop();
            }

            if (pq.empty()) break;

            // build res
            if (!pq.empty()) {
                auto [count, releaseTime, ch] = pq.top();
                res += ch;
                pq.pop();
                
                if (count > 1) {
                    q.push( {count-1, time+2, ch} );
                }
            }

            // increment time
            time++;
        }
        if (!pq.empty() || !q.empty()) return "";
        return res;
    }
};