class Solution 
{
    public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        if (tasks.empty()) return 0;

        // build freq
        unordered_map<char, int> freq;
        for (char ch : tasks) {
            freq[ch]++;
        }

        auto comp = [](const auto& a, const auto& b){
            return a.second < b.second; // higher freq on top
        };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(comp)> pq{comp};
        for (auto& [ch, count] : freq) {
            pq.push( {ch, count} );
        }

        queue<tuple<char, int, int>> q; // { task, newCount, releaseTime }
        int currTime = 0;
        while (!pq.empty() || !q.empty()) {
            currTime++;

            if (!pq.empty()) {
                auto [task, count] = pq.top();
                pq.pop();
                if (count > 1) {
                    q.push( {task, count-1, currTime + n} ); 
                }
            }

            if (!q.empty() && currTime >= get<2>(q.front())) {
                char task = get<0>(q.front());
                int count = get<1>(q.front());
                q.pop();
                pq.push( {task, count} );
            }
        }
        return currTime;
    }
};