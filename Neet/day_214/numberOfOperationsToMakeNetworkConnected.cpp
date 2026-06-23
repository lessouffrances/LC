
// the least number of edges to connect n nodes is n-1
// res = (number of connected components - 1)
// see if #connections >= n-1?

class Solution 
{
    public:
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        if (connections.empty()) return -1;
        buildGraph(n, connections);

        int numOfCC = 0;
        for (int node=0; node<n; node++) {
            if (visited.count(node)) continue;
            dfs(node);
            numOfCC++;
        }

        int numAvailableEdges = connections.size();
        return (numAvailableEdges >= n-1) ? numOfCC-1 : -1;
    }
    private:
    unordered_map<int, vector<int>> graph;
    unordered_set<int> visited; // global visited

    void dfs(int u) 
    {
        visited.insert(u);
        for (auto& v : graph[u]) {
            if (visited.count(v)) continue;
            dfs(v);
        }
    }

    void buildGraph(int n, vector<vector<int>>& connections)
    {
        // for one isolated node
        for (int node=0; node<n; node++) {
            graph[node] = {};
        }

        for (auto& conn : connections) {
            int u = conn[0];
            int v = conn[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }
};