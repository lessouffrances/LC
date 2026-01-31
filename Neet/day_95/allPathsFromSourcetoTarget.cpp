class Solution 
{
    public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        if (graph.empty()) return {};
        int n = graph.size();

        vector<int> startPath = {0};
        dfs(0, startPath, graph, n);
        return res;
    }
    private:
    vector<vector<int>> res;
    void dfs(int u, vector<int>& currPath, vector<vector<int>>& graph, int n)
    {
        if (u == n-1) {
            res.push_back(currPath);
            return;
        }

        for (auto& neighbor : graph[u]) {
            currPath.push_back(neighbor);
            dfs(neighbor, currPath, graph, n);
            currPath.pop_back();
        }
    }
};