


// Time: O(N log K), where N is the size of the input and K is the number of unique tasks 
// Space: O(K)

class Solution 
{
    public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        if (tasks.empty()) return 0;

        // build freq
        unordered_map<char, int> freq;
        for (char task : tasks) {
            freq[task]++;
        }

        // a pq with highest freq on top
        // { count, releaseTime, taskChar }
        priority_queue<tuple<int, int, char>, vector<tuple<int, int, char>>, less<tuple<int, int, char>>> pq;
        queue<tuple<int, int, char>> q;

        // push all to pq
        for (auto& [ch, count] : freq) {
            pq.push( {count, 0, ch} );
        }

        int time = 0;
        while (!pq.empty() || !q.empty()) {
            // release all tasks from queue
            while (!q.empty() && get<1>(q.front()) <= time) {
                pq.push(q.front());
                q.pop();
            }

            // after release but find the pq is empty
            // forward time to the next task's time
            if (pq.empty()) {
                time = get<1>(q.front());
                continue;
            }

            // process and push to queue 
            auto [count, releaseTime, taskChar] = pq.top();
            pq.pop();

            if (count > 1) {
                q.push( {count-1, time+n+1, taskChar} ); 
            }
            time++;
        }
        return time;
    }
};