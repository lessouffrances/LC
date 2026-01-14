class Solution {
    public:
        string reorganizeString(string s) {
            // construct freqMap
            unordered_map<char, int> freq;
            for (char c : s) {
                freq[c]++;
            }
    
            priority_queue<tuple<int, int, char>, vector<tuple<int, int, char>>, less<tuple<int, int, char>>> pq;
            queue<tuple<int, int, char>> q;
    
            for (auto& [ch, count] : freq) {
                pq.push( {count, 0, ch} );
            }
    
            int t = 0;
            string res = "";
            while (!pq.empty() || !q.empty()) {
                // release the chars from hold
                while (!q.empty() && get<1>(q.front()) <= t) {
                    pq.push(q.front());
                    q.pop();
                }
    
                if (pq.empty()) break;
    
                auto [count, releaseTime, ch] = pq.top();
                pq.pop();
    
                res += ch;
                if (count > 1) {
                    q.push( {count-1, t+2, ch} );
                }
                t++;
            }
    
            if (!q.empty() || !pq.empty()) return "";
            return res;
        }
    };