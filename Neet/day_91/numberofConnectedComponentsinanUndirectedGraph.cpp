class Solution 
{
    public:
    int countComponents(int n, vector<vector<int>>& edges) 
    {
        if (edges.empty()) return 0;

        buildGraph(n, edges);
        int res = 0;
        for (int i=0; i<n; i++) {
            if (visited.count(i)) continue;
            dfs(graph, i);
            res++;
        }
        return res;
    }
    
    private:
    unordered_map<int, vector<int>> graph;
    unordered_set<int> visited;
    void dfs(unordered_map<int, vector<int>>& graph, int u) 
    {
        visited.insert(u);

        if (graph.count(u)) {
            for (auto& v : graph[u]) {
                if (visited.count(v)) continue;
                dfs(graph, v);
            }
        }
    }

    void buildGraph(int n, vector<vector<int>>& edges) 
    {
        for (int i=0; i<n; i++) {
            graph[i] = {};
        }
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }
};