// the least number of edges to connect n nodes is n-1
// res = (number of connected components - 1)
// if #connections >= n-1 return res, else return -1

class Solution 
{
    public:
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        // find the num of CC
        // FULL DFS on the graph
        buildGraph(n, connections);

        int numOfCC = 0;
        for (int node=0; node<n; node++) {
            if (visited.count(node)) continue;
            dfs(node);
            numOfCC++;
        }
        int res = numOfCC - 1;
        return connections.size() >= n-1 ? res : -1;
    }

    private:
    unordered_map<int, vector<int>> graph; // essentially, adjList
    unordered_set<int> visited;

    void buildGraph(int n, vector<vector<int>>& connections)
    {
        for (int node=0; node<n; node++) {
            graph[node] = {};
        }
        for (auto& conn : connections) {
            int u = conn[0];
            int v = conn[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }

    // for finding CC
    void dfs(int u)
    {
        visited.insert(u);
        for (auto& v : graph[u]) {
            if (visited.count(v)) continue;
            dfs(v);
        }
    }
};