
// greedy + maxHeap by freq
class Solution 
{
    public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        if (tasks.empty()) return 0;

        // tuple<int, int, char>
        // the format is:
        // { count, releaseTime, task }
        priority_queue<tuple<int, int, char>> pq;
        queue<tuple<int, int, char>> q; // for holding the tasks when it cannot be added to the CPU

        // build freq
        unordered_map<char, int> freq;
        for (char ch : tasks) {
            freq[ch]++;
        }

        // push all pairs of count, ch onto the pq
        // then the mechanism of a maxHeap will automatically
        // arrange the task with highest freq on top
        for (auto& [ch, count] : freq) {
            pq.push( {count, 0, ch} );
        }

        int time = 0;
        while (!pq.empty() || !q.empty()) {
            // release all tasks from q
            // when can a task be released?
            // when the releaseTime <= currTime
            while (!q.empty() && get<1>(q.front()) <= time) {
                pq.push(q.front());
                q.pop();
            }

            // if there's nothing to be released,
            // jump to the next releaseTime 
            if (pq.empty()) {
                time = get<1>(q.front());
                continue;
            };

            // process one task
            auto [count, releaseTime, ch] = pq.top();
            pq.pop();
            if (count > 1) q.push( {count-1, time+n+1, ch} );

            time++;
        }
        return time;
    }
};
