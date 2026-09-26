class Solution 
{
    public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        if (tasks.empty()) return 0;

        unordered_map<char, int> freq;
        for (char ch : tasks) {
            freq[ch]++;
        }

        // maxHeap, higher frequency on top
        priority_queue<pair<int, char>, vector<pair<int, char>>, less<pair<int, char>>> pq;
        // seed all chars
        for (auto& [ch, count] : freq) {
            pq.push( {count, ch} );
        }

        queue<tuple<int, int, char>> q; // { currCount, nextReleasableTime, ch }

        int t = 0;
        while (!pq.empty() || !q.empty()) {
            // see if anything can be unfreeze from the q
            while (!q.empty() && get<1>(q.front()) <= t) {
                auto [currCount, nextReleasableTime, ch] = q.front(); q.pop();
                pq.push( {currCount, ch} );
            }

            // release from the highest frequency
            if (!pq.empty()) {
                auto [currCount, ch] = pq.top();
                pq.pop();
                t++;
                if (currCount > 1) q.push( {currCount-1, t+n, ch} );
            } else {
                t = get<1>(q.front());
            }
        }
        return t;
    }
};