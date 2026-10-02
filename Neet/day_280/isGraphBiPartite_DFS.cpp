class Solution 
{
    public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        if (graph.empty()) return false;
        int n = graph.size();

        for (int node=0; node<n; node++) {
            if (nodeToColor.count(node)) continue;
            if (!dfs(1, node, graph)) return false;
        }
        return true;
    }

    private:
    unordered_map<int, int> nodeToColor;
    bool dfs(int color, int u, vector<vector<int>>& graph)
    {
        nodeToColor[u] = color;
        
        for (auto& v : graph[u]) {
            if (nodeToColor.count(v) && nodeToColor[v] == color) return false;
            if (nodeToColor.count(v)) continue;
            if (!dfs(-color, v, graph)) return false;
        }
        return true;
    }
};