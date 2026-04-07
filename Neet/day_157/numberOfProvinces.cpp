



class Solution 
{
    public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        buildGraph(isConnected);

        // full DFS on graph
        int numOfProvinces = 0;
        for (auto& [node, _] : graph) {
            if (visited.count(node)) continue;
            numOfProvinces++;
            dfs(node);n
        }
        return numOfProvinces;
    }
    private:
    unordered_map<int, vector<int>> graph; 
    unordered_set<int> visited;

    void dfs(int u) 
    {
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
                if (isConnected[u][v] == 1) {
                    graph[u].push_back(v);
                    graph[v].push_back(u);
                }
            }
        }
    }
};