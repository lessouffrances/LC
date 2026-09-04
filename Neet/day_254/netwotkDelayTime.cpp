class Solution
{
    public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        if (times.empty()) return n == 1 ? 0 : -1;

        buildGraph(times, n);
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        // min-heap on { distance, node } 
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push( {0, k} );
        unordered_set<int> visited;

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (visited.count(u)) continue;
            visited.insert(u);

            for (auto& [v, w] : graph[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            maxTime = max(maxTime, dist[i]);
        }
        return maxTime; 
    }

    private:
    unordered_map<int, vector<pair<int,int>>> graph;  
    void buildGraph(vector<vector<int>>& times, int n)
    {
        for (auto& t : times) {
            int u = t[0], v = t[1], w = t[2];
            graph[u].push_back({v, w});
        }
    }
};