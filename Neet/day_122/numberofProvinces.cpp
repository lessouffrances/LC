class Solution 
{
    public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        if (isConnected.empty()) return 0;
        int n = isConnected.size();

        buildGraph(isConnected);
    
        // FULL-DFS
        int numOfProvinces = 0;
        for (int i=0; i<n; i++) {
            if (visited.count(i)) continue;
            dfs(i, graph);
            numOfProvinces++;
        }
        return numOfProvinces;
    }

    private:
    unordered_map<int, vector<int>> graph;
    unordered_set<int> visited; // global tracker, across all dfs calls
    void dfs(int u, unordered_map<int, vector<int>>& graph) 
    {
        visited.insert(u);

        for (int v : graph[u]) {
            if (visited.count(v)) continue;
            dfs(v, graph);
        }
    }
    void buildGraph(vector<vector<int>>& isConnected) 
    {
        for (int u=0; u<isConnected.size(); u++) {
            for (int v=0; v<isConnected[0].size(); v++) {
                if (isConnected[u][v] == 1) {
                    graph[u].push_back(v);
                    graph[v].push_back(u);
                }
            }
        }
    }
};