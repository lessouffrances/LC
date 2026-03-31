



class Solution 
{
    public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        if (isConnected.empty()) return 0;
        int n = isConnected.size();
        buildGraph(isConnected);

        // FULL-DFS 
        int res = 0;
        for (int i=0; i<n; i++) {
            if (visited.count(i)) continue;
            dfs(i);
            res++;
        }
        return res;
    }

    private:
    unordered_map<int, vector<int>> graph;
    unordered_set<int> visited;
    void dfs(int u) {
        visited.insert(u);

        for (int v : graph[u]) {
            if (visited.count(v)) continue;
            dfs(v);
        }
    }
    void buildGraph(vector<vector<int>>& isConnected)
    {
        int ROW = isConnected.size();
        int COL = isConnected[0].size();

        for (int u=0; u<ROW; u++) {
            for (int v=0; v<COL; v++) {
                if (isConnected[u][v] == 1 && u != v) {
                    graph[u].push_back(v);
                    graph[v].push_back(u);
                }
            }
        }
    }
};