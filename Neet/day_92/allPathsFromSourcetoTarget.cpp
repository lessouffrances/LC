class Solution 
{
    public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        if (graph.empty()) return {};
        int n = graph.size();
        buildGraph(graph);

        vector<int> startPath;
        startPath.push_back(0);
        dfs(0, n-1, startPath);
        return res;
    }
    private:
    unordered_map<int, vector<int>> G;
    vector<vector<int>> res;
    void dfs(int u, int target, vector<int>& currPath) 
    {
        if (u == target) {
            res.push_back(currPath);
            return;
        }
        if (G.count(u)) {
            for (auto& v : G[u]) {
                currPath.push_back(v);
                dfs(v, target, currPath);
                currPath.pop_back();
            }
        }
    }
    void buildGraph(vector<vector<int>>& graph) 
    {
        if (graph.empty()) return;
        int n = graph.size();

        for (int i=0; i<n; i++) {
            G[i] = graph[i];
        }
    }
};