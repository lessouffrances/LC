


// Time: O(N log K), N is the size of the input string and K is the number of unique chars 
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

        // { freq, releaseTime, char }
        // higher freq on top
        priority_queue<tuple<int, int, char>, vector<tuple<int, int, char>>, less<tuple<int, int, char>>> pq;
        queue<tuple<int, int, char>> q;

        // push all [char, count] pairs on to the pq for start
        for (auto& [ch, count] : freq) {
            pq.push( {count, 0, ch} ); // assume time starts at 1
        }

        int time = 0;
        string res = "";
        while (!q.empty() || !pq.empty()) {
            // release chars from queue
            while (!q.empty() && get<1>(q.front()) <= time) {
                pq.push( q.front() );
                q.pop();
            }

            // now q contains all the char that can appear next;
            if (pq.empty()) break;

            // append to next
            auto [count, releaseTime, ch] = pq.top();
            pq.pop();

            res += ch;
            // queue this char if count > 1
            if (count > 1) {
                q.push( {count-1, time+2, ch} );
            }

            // increment time
            time++;
        }

        if (!q.empty() || !pq.empty()) return "";
        return res;
    }
};