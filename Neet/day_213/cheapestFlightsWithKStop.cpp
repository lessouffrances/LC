class Solution 
{
    public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
    {
        if (flights.empty()) return 0;
        buildGraph(n, flights);

        // { dist, currEndpoint, numStopsTraveled }
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap;
        minHeap.push( {0, src, 0} );
        // currEndPoint, numStops
        vector<vector<int>> dp(n, vector<int>(k+2, INT_MAX));
        dp[src][0] = 0;

        while (!minHeap.empty()) {
            int dist = get<0>(minHeap.top());
            int u = get<1>(minHeap.top());
            int numStops = get<2>(minHeap.top());
            minHeap.pop();

            if (u == dst) return dist;
            if (numStops > k) continue;
            if (dist > dp[u][numStops]) continue;
            for (auto& [v, weight] : graph[u]) {
                if (dp[v][numStops+1] <= dp[u][numStops] + weight) continue;
                dp[v][numStops+1] = dp[u][numStops] + weight;
                minHeap.push( {dp[v][numStops+1], v, numStops+1} );
            }
        }
        return -1;
    }

    private:
    unordered_map<int, vector<pair<int, int>>> graph; // adjList
    void buildGraph(int n, vector<vector<int>>& flights)
    {
        for (int i=0; i<n; i++) {
            graph[i] = {};
        }

        for (auto& fl : flights) {
            int u = fl[0];
            int v = fl[1];
            int weight = fl[2];
            graph[u].push_back( {v, weight} );
        }
    }
};