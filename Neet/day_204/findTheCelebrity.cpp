class Solution 
{
    public:
    int findCelebrity(int n) 
    {
        if (n == 0) return -1;

        buildGraph(n);

        // step 1: find the one node that has no outdegree
        for (auto& [u, adjList] : graph) {
            if (adjList.empty()) {
                bool found = true;
                for (auto& [v, adjList] : graph) {
                    if (v != u && !graph[v].count(u)) {
                        found = false;
                        break;
                    }
                }
                if (found) return u;
            }
        }
        return -1;
    }

    private:

    // node: {n1, n2, n3}
    unordered_map<int, unordered_set<int>> graph;
    void buildGraph(int n)
    {
        for (int u=0; u<n; u++) {
            graph[u] = {}; // ensure every node exists
            for (int v=0; v<n; v++) {
                if (u == v) continue;
                if (knows(u, v)) {
                    graph[u].insert(v);
                }
            }
        }
    }
};