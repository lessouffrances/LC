


class Solution 
{
    public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        
        buildGraph(isConnected);
        int n = isConnected.size();

        int count = 0;
        for (int i=0; i<n; i++) {
            if (visited.count(i)) continue;
            visited.insert(i);
            dfs(i, graph);
            count++;
        }
        return count;
    }
    private:
    unordered_map<int, vector<int>> graph;
    unordered_set<int> visited;
    void dfs(int u, unordered_map<int, vector<int>>& graph)
    {
        for (auto& v : graph[u]) {
            if (visited.count(v)) continue;
            visited.insert(v);
            dfs(v, graph);
        }
    }
    void buildGraph(vector<vector<int>>& isConnected)
    {
        int n = isConnected.size();

        for (int u=0; u<n; u++) {
            for (int v=0; v<n; v++) {
                if (u == v) continue;
                if (isConnected[u][v] == 1) {
                    graph[u].push_back(v);
                    graph[v].push_back(u);
                }
            }
        }
    }
};