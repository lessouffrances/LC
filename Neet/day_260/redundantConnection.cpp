class Solution 
{
    public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            visited.clear();

            if (dfsIsConnected(u, v)) return edge;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        return {};
    }

    private:
    unordered_map<int, vector<int>> graph;
    unordered_set<int> visited;

    bool dfsIsConnected(int src, int dest) 
    {
        if (src == dest) return true;
        visited.insert(src);

        for (auto& v : graph[src]) {
            if (visited.count(v)) continue;
            if (dfsIsConnected(v, dest)) return true;
        }
        return false;
    }
};