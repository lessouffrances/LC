class Solution 
{
    public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        if (flights.empty()) return 0;

        buildGraph(flights, n);
        vector<vector<int>> dp(n, vector<int>(k+2, INT_MAX));
        dp[src][0] = 0;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq; // {dist, u, numOfStops}

        pq.push( {0, src, 0} );

        while (!pq.empty()) {

        }

        


    }
    private:
    unordered_map<int, vector<pair<int, int>>> graph;
    void buildGraph(vector<vector<int>>& flights, int n)
    {
        for (int i=0; i<n; i++) {
            graph[i] = {}; 
        }
        for (const auto& flight : flights) {
            int u = flight[0];
            int v = flight[1];
            int weightUToV = flight[2];

            graph[u].push_back( {v, weightUToV} );
        }
    }
};