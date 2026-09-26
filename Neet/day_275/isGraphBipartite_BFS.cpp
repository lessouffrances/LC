class Solution 
{
    public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        if (graph.empty()) return false;
        int n = graph.size();
        unordered_map<int, int> nodeToColor;

        auto bfs = [&](queue<pair<int, int>>& q) {
            while (!q.empty()) {
                auto [u, color] = q.front(); q.pop();
                for (auto& v : graph[u]) {
                    if (nodeToColor.count(v) && nodeToColor[v] == color) return false; 
                    if (nodeToColor.count(v)) continue;
                    q.push( {v, -color} );
                    nodeToColor[v] = -color;
                }
            }
            return true;
        };

        for (int i=0; i<n; i++) {
            if (nodeToColor.count(i)) continue;
            // seed q
            queue<pair<int, int>> q;
            // start with this node and color 1
            q.push( {i, 1} );
            if (!bfs(q)) return false;
        }
        return true;
    }
};