class Solution 
{
    public:
    int countComponents(int n, vector<vector<int>>& edges) 
    {
        buildGraph(n, edges);

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
    void dfs(int u)
    {
        visited.insert(u);

        for (int v : graph[u]) {
            if (visited.count(v)) continue;
            dfs(v);
        }
    }

    void buildGraph(int n, vector<vector<int>>& edges)
    {
        for (int i=0; i<n; i++) {
            graph[i] = {};
        }
        for (int i=0; i<graph.size(); i++) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }
};