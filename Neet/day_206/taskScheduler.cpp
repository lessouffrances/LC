class Solution 
{
    public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        if (tasks.empty()) return 0;

        priority_queue<tuple<int, int, char>> pq; // { count, releaseTime, char }
        queue<tuple<int, int, char>> q; // cool-down room

        // build freq
        unordered_map<char, int> freq;
        for (char ch : tasks) {
            freq[ch]++;
        }

        for (auto& [ch, count] : freq) {
            pq.push( {count, 0, ch} );
        }

        int time = 0;
        while (!pq.empty() || !q.empty()) {
            // release from q
            while (!q.empty() && get<1>(q.front()) <= time) {
                pq.push( q.front() );
                q.pop();
            } 

            // if there's nothing to be released, jump to the next releasable time
            if (pq.empty()) {
                time = get<1>(q.front());
                continue;
            }

            // process one task
            auto [count, releaseTime, ch] = pq.top();
            pq.pop();

            if (count > 1) q.push( {count-1, time+n+1, ch} );
            time++;
        }
        return time;
    } 
};