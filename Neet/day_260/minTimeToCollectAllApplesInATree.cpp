class Solution 
{
    public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) 
    {
        buildGraph(n, edges);
        dfs(0, -1, hasApple);
        return res;
    }

    private:
    unordered_map<int, vector<int>> graph;
    // unordered_set<int> visited;
    int res = 0;
    bool dfs(int u, int parent, vector<bool>& hasApple)
    {
        // visited.insert(u);

        bool subtreeHasApple = hasApple[u];
        for (auto& v : graph[u]) {
            if (v == parent) continue;
            bool childHasApple = dfs(v, u, hasApple);
            if (childHasApple) {
                res += 2;
                subtreeHasApple = true;
            }
        }
        return subtreeHasApple;
    }

    void buildGraph(int n, vector<vector<int>>& edges) {
        for (int i=0; i<n; i++) graph[i] = {};
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }
};