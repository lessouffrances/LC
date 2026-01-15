class Solution 
{
    public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        if (graph.empty()) return {};

        buildGraph(graph);
        int n = graph.size();
        vector<int> startPath;
        startPath.push_back(0);
        dfs(0, startPath, n);
        return res;
    }

    private:
    unordered_map<int, vector<int>> G;
    vector<vector<int>> res;
    
    void dfs(int u, vector<int>& currPath, int n)
    {
        if (u == n-1) {
            res.push_back(currPath);
            return;
        }

        if (G.count(u)) {
            for (auto& v : G[u]) {
                currPath.push_back(v);
                dfs(v, currPath, n);
                currPath.pop_back(); // backtrack
            }
        }
    }

    void buildGraph(vector<vector<int>>& graph)
    {
        if (graph.empty()) return;
        int n = graph.size(); // num of nodes

        for (int i=0; i<n; i++) {
            G[i] = graph[i];
        }
    }
};