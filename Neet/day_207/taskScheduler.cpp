class Solution 
{
    public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        if (tasks.empty()) return 0;

        // maxHeap to put the highest freq on top
        priority_queue<tuple<int, int, char>> pq;
        queue<tuple<int, int, char>> q;

        unordered_map<char, int> freq;
        for (char ch : tasks) {
            freq[ch]++;
        }

        // push all pair on freq onto the pq
        for (auto& [ch, count] : freq) {
            pq.push( {count, 0, ch} );
        }

        int time = 0;
        while (!pq.empty() || !q.empty()) {
            // release all tasks from the cool-down room
            while (!q.empty() && get<1>(q.front()) <= time) {
                pq.push(q.front());
                q.pop();
            }

            if (pq.empty()) {
                time = get<1>(q.front());
                continue;
            }

            auto [count, releaseTime, ch] = pq.top();
            pq.pop();
            if (count > 1) q.push( {count-1, time+1+n, ch} );
            time++;
        }
        return time;
    }
};