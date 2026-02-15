class Solution 
{
    public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        if (source == destination) return true;
        if (edges.empty()) return false;

        buildGraph(edges);
        return dfs(source, destination, graph);
    }
    private:
    unordered_map<int, vector<int>> graph;
    unordered_set<int> visited;
    bool dfs(int u, int dest, unordered_map<int, vector<int>>& graph)
    {
        if (u == dest) return true;

        for (int v : graph[u]) {
            if (visited.count(v)) continue;
            visited.insert(v);
            if (dfs(v, dest, graph)) return true;
        }
        return false;
    }

    void buildGraph(vector<vector<int>>& edges)
    {
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }
};