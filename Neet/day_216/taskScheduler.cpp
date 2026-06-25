
// greedy: highest frequency comes first
// maxHeap: always hand me the most frequent one with some time interval N 
//    => can store 3 params: currFreq, releaseTime, taskChar
// queue: FIFO nature: iterate until the queue is empty

// tasks = ["A","A","A","A","A","B","B","B"], n = 2
// freq = { {"A", 5}, {"B", 3} }
// time = 6
// maxHeap = [ ]
// queue = [ ]
// cpu = "BABABA  A  A"

class Solution 
{
    public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        if (tasks.empty()) return 0;

         // {currFreq, releaseTime, taskChar}
        priority_queue<tuple<int, int, int>> pq;
        queue<tuple<int, int, int>> q;

        unordered_map<char, int> freq;
        for (char ch : tasks) {
            freq[ch]++;
        }

        // push all pairs on freq with time is 0 to the pq
        for (auto& [task, count] : freq) {
            pq.push( {count, 0, task} );
        }

        int t = 0;
        while (!pq.empty() || !q.empty()) {
            while (!q.empty() && t >= get<1>(q.top())) {
                pq.push(q.front());
                q.pop();
            }

            // need fast-forward
            if (pq.empty()) {
                t = get<1>(q.top());
                continue;
            }

            // process one task
            auto [currFreq, releaseTime, taskChar] = pq.top();
            if (currFreq > 1) q.push( {currFreq-1, releaseTime+n+1, taskChar} );
            t++;
        }
        return t;
    }
};