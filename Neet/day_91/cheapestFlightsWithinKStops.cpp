class Solution 
{
    public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
    {
        if (flights.empty()) return 0;
        buildGraph(n, flights); 

        // { dist, u, numOfStops }
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push( {0, src, 0} );
        vector<vector<int>> dp(n, vector<int>(k+2, INT_MAX));
        // k = maximum number of stops (intermediate cities)
        // But you need k+1 edges (flights) to have k stops
        // Array indices go from 0 to k+1, so size must be k+2
        dp[src][0] = 0;

        while (!pq.empty()) {
            int dist = get<0>(pq.top());
            int u = get<1>(pq.top());
            int numOfStops = get<2>(pq.top());
            pq.pop();

            if (u == dst) return dist;
            if (numOfStops > k) continue;
            if (dist > dp[u][numOfStops]) continue;

            if (graph.count(u)) {
                for (auto& [v, weight] : graph[u]) {
                    if (dp[v][numOfStops+1] <= dp[u][numOfStops] + weight) continue;
                    dp[v][numOfStops+1] = dp[u][numOfStops] + weight;
                    pq.push( {dp[v][numOfStops+1], v, numOfStops+1} );
                }
            }
        }
        return -1;
    }
    private:
    unordered_map<int, vector<pair<int, int>>> graph;
    void buildGraph(int n, vector<vector<int>>& flights)
    {
        for (int i=0; i<n; i++) {
            graph[i] = {};
        }
        for (auto& flight : flights) {
            int u = flight[0];
            int v = flight[1];
            int weight = flight[2];
            graph[u].push_back( {v, weight} );
        }
    }
};