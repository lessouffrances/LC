class Solution 
{
    public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        if (isConnected.empty()) return 0;
        buildGraph(isConnected);
        int n = isConnected.size();
        // full DFS
        int numOfCC = 0;
        for (int i=0; i<n; i++) {
            if (visited.count(i)) continue;
            dfs(i);
            numOfCC++;
        }
        return numOfCC;
    }

    private:
    unordered_map<int, vector<int>> graph; // adjList
    unordered_set<int> visited;
    void buildGraph(vector<vector<int>>& isConnected)
    {
        int n = isConnected.size();
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (isConnected[i][j] == 1) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
    }

    void dfs(int u)
    {
        visited.insert(u);
        if (graph.count(u)) {
            for (int v : graph[u]) {
                if (visited.count(v)) continue;
                dfs(v);
            }
        }
    }
};