class Solution 
{
    public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        if (graph.empty()) return false;
        int n = graph.size();
        unordered_map<int, int> nodeToColor;

        auto bfs = [&](queue<pair<int, int>>& q) -> bool {
            while (!q.empty()) {
                auto [node, color] = q.front();
                q.pop();

                for (auto& v : graph[node]) {
                    if (nodeToColor.count(v) && nodeToColor[v] == color) return false;
                    if (nodeToColor.count(v)) continue;
                    nodeToColor[v] = -color;
                    q.push( {v, -color} );
                }
            }
            return true;
        };

        for (int node=0; node<n; node++) {
            if (nodeToColor.count(node)) continue;
            queue<pair<int, int>> q;
            q.push( {node, 1} );
            nodeToColor[node] = 1;
            if (!bfs(q)) return false;
        }
        return true;
    }
};