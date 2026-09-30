class Solution 
{
    public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        if (graph.empty()) return false;

        int n = graph.size();
        for (int i=0; i<n; i++) {
            if (nodeToColor.count(i)) continue;
            if (!dfsIsGraphBiPartite(i, 1, graph)) return false;
        }
        return true;
    }

    private:
    unordered_map<int, int> nodeToColor;
    bool dfsIsGraphBiPartite(int node, int color, vector<vector<int>>& graph)
    {
        nodeToColor[node] = color;

        for (auto& v : graph[node]) {
            if (nodeToColor.count(v) && nodeToColor[v] == color) return false;
            if (nodeToColor.count(v)) continue;
            if (!dfsIsGraphBiPartite(v, -color, graph)) return false;
        }
        return true;
    }
};