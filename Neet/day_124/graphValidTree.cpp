class Solution 
{
    public:
   
    bool validTree(int n, vector<vector<int>>& edges) 
    {
        buildGraph(n, edges);
        if (dfsDetectCycle(0, -1)) return false;
        return visited.size() == n;
    }
    private:
    unordered_map<int, vector<int>> graph;
    unordered_set<int> visited;
    bool dfsDetectCycle(int u, int parent) 
    {
        visited.insert(u);

        for (int v : graph[u]) {
            if (v == parent) continue;
            if (visited.count(v)) return true;
            if (dfsDetectCycle(v, u)) return true;
            
        }
        return false;
    }

    void buildGraph(int n, vector<vector<int>>& edges)
    {
        for (int i=0; i<n; i++) {
            graph[i] = {};
        }
        for (int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }
};