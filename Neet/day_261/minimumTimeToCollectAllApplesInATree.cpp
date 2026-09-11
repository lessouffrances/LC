class Solution 
{
    public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) 
    {
        buildGraph(edges);
        dfsSubtreeHasApple(0, -1, hasApple);
        return res;
    }

    private:
    int res;
    unordered_map<int, vector<int>> graph;
    void buildGraph(vector<vector<int>>& edges)
    {
        int n = edges.size();
        for (int i=0; i<n; i++) graph[i] = {};
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }

    bool dfsSubtreeHasApple(int u, int parent, vector<bool>& hasApple)
    {
        bool subtreeHasApple = hasApple[u];
        for (auto& v : graph[u]) {
            if (v == parent) continue;
            if (dfsSubtreeHasApple(v, u, hasApple)) {
                subtreeHasApple = true;
                res += 2;
            }
        }
        return subtreeHasApple;
    }
};