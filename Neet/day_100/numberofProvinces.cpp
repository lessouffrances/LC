class Solution 
{
    public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        if (isConnected.empty()) return 0;
        int n = isConnected.size();
        buildGraph(isConnected, n);

        int numOfCC = 0;
        for (int i=1; i<n+1; i++) {
            if (visited.count(i)) continue;
            numOfCC++;
            dfs(i, graph);
        }

        return numOfCC;
    }
    private:
    unordered_map<int, vector<int>> graph;
    unordered_set<int> visited;
    void dfs(int u, unordered_map<int, vector<int>>& graph) 
    {
        for (int v : graph[u]) {
            if (visited.count(v)) continue;
            visited.insert(v);
            dfs(v, graph);
        }
    }

    void buildGraph(vector<vector<int>>& isConnected, int n)
    {
        if (isConnected.empty()) return;

        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (isConnected[i][j] == 1) {
                    graph[i+1].push_back(j+1);
                    graph[j+1].push_back(i+1);
                }
            }
        }
    }
};