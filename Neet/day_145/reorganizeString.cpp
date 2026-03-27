



// Time: O(N logN)
// Space: O(N), all bounded by N
class Solution 
{
    public:
    string reorganizeString(string s) 
    {
        if (s.length() == 0) return "";
        unordered_map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }

        // with higher freq on top
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, less<tuple<int, int, int>>> pq;
        queue<tuple<int, int, int>> q;

        // push all [char, count] pairs onto pq for start
        for (auto& [ch, count] : freq) {
            pq.push( {count, 0, ch} );
        }

        int time = 0;
        string res = "";
        while (!q.empty() || !pq.empty()) {
            // release the chars from hold
            while (!q.empty() && get<1>(q.front()) <= time) {
                pq.push( q.front() );
                q.pop();
            }

            if (pq.empty()) break;

            // append the char on top of the pq
            auto [count, releaseTime, ch] = pq.top();
            pq.pop();
            res += ch;

            // if more than 2 left for this char
            if (count >= 1) {
                q.push( {count-1, time+2, ch} );
            }

            time++;
        }

        // if there are something left,
        // we cannot prevent adjacent duplication
        if (!q.empty() || !pq.empty()) return "";
        return res;
    }
};