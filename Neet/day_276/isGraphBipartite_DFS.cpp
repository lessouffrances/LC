class Solution 
{
    public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        for (int i=0; i<n; i++) {
            if (!nodeToColor.count(i)) {
                if (!dfsColor(i, 1, graph)) return false;
            }
        }
        return true;
    }

    private:
    // color all nodes connected to this node as the passed-in color
    unordered_map<int, int> nodeToColor;
    bool dfsColor(int u, int color, vector<vector<int>>& graph)
    {
        nodeToColor[u] = color;

        for (auto& v : graph[u]) {
            if (nodeToColor.count(v) && nodeToColor[v] == color) return false;
            if (nodeToColor.count(v)) continue;
            // if I color this node using a diff color and cannot workout
            if (!dfsColor(v, -color, graph)) return false;
        }
        return true;
    }
};