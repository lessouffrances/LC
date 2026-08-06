class Solution 
{
    public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        if (tasks.empty()) return 0;
        unordered_map<char, int> freq;
        for (char task : tasks) freq[task]++;

        // maxHeap
        priority_queue<tuple<int, int, char>, vector<tuple<int, int, char>>, less<tuple<int, int, char>>> pq;
        for (auto& [task, count] : freq) {
            pq.push( {count, 0, task} );
        }
        // { freq, releaseTime, task }
        queue<tuple<int, int, char>> q;

        int time = 0;
        while (!pq.empty() || !q.empty()) {
            // release all the tasks from q
            while (!q.empty() && time >= get<1>(q.front())) {
                pq.push( q.front() );
                q.pop();
            }

            if (pq.empty()) {
                time = get<1>(q.front());
                continue;
            }

            auto [currFreq, releaseTime, taskChar] = pq.top();
            pq.pop();
            if (currFreq > 1) q.push( {currFreq-1, releaseTime+n+1, taskChar} );
            time++;
        }
        return time;
    } 
};