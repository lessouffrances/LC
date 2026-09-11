class Solution 
{
    public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            visited.clear(); // very important
            if (dfsIsReachable(u, v)) return e;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        return {};
    }

    private:
    unordered_map<int, vector<int>> graph;
    unordered_set<int> visited;
    bool dfsIsReachable(int src, int dest)
    {
        if (src == dest) return true;
        visited.insert(src);

        for (auto& v : graph[src]) {
            if (visited.count(v)) continue;
            if (dfsIsReachable(v, dest)) return true;
        }
        return false;
    }
};
