class Solution 
{
    public:
    int countPaths(int n, vector<vector<int>>& roads) 
    {
        const int MOD = 1e9+7;

        buildGraph(n, roads);
        // {time, v}, minTime on top
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

        // shortest time to each node
        vector<long long> shortestTime(n, LLONG_MAX);
        // number of ways to reach each node in shortest time
        vector<int> pathCount(n, 0);

        // time to node 0
        shortestTime[0] = 0;
        // 1 way to reach node 0
        pathCount[0] = 1;

        // seed node 0
        pq.push( {0, 0} );
        while (!pq.empty()) {
            auto [currTime, currNode] = pq.top();
            pq.pop();

            if (currTime > shortestTime[currNode]) continue;
            for (auto& [neighbor, time] : graph[currNode]) {
                if (currTime + time < shortestTime[neighbor]) {
                    // worth updating
                    shortestTime[neighbor] = currTime+time;
                    pathCount[neighbor] = pathCount[currNode];
                    pq.push( {shortestTime[neighbor], neighbor} );
                } else if (currTime + time == shortestTime[neighbor]) {
                    pathCount[neighbor] = (pathCount[neighbor]+pathCount[currNode]) % MOD;
                }
            }
        }
        return pathCount[n-1];
    }

    private:
    unordered_map<int, vector<pair<int, int>>> graph; // {v, time}
    void buildGraph(int n, vector<vector<int>>& roads)
    {
        for (auto& rd : roads) {
            int u = rd[0];
            int v = rd[1];
            int t = rd[2];
            graph[u].push_back( {v, t} );
            graph[v].push_back( {u, t} );
        }
    }
}; 