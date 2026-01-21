class Solution 
{
    public:
    int findCelebrity(int n) 
    {
        // use knows to build the edges
        buildEdges(n);
        buildGraph(edges);

        // knows no one: no outdegree
        // everyone knows her
        for (auto& [u, adjList] : graph) {
            if (graph[u] == {}) {
                bool found = true;

                for (auto& [v, adjList] : graph) {
                    if (v != u && !graph[v].count(u)) {
                        found = false;
                    }
                }
                if (found) return u;
            }
        }
        return -1;
    }

    private:
    vector<vector<int>> edges;
    unordered_map<int, vector<int>> graph;
    void buildGraph(vector<vector<int>>& edges)
    {
        if (edges.empty()) return;

        for (int u=0; u<n; u++) {
            graph[u] = {};
        }
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
        }
    }

    void buildEdges(int n) {
        for (int i=0; i<n; i++) {
            for (int j=n-1; j>=0; j--) {
                if (knows(i, j)) {
                    edges.push_back( {i, j} );
                }
                if (knows(j, i)) {
                    edges.push_back( {j, i} );
                }
            }
        }
    }
};