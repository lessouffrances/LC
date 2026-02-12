class Solution 
{
    public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        if (graph.empty()) return {};
        int n = graph.size();
        vector<int> startPath;
        startPath.push_back(0);
        dfs(0, n, startPath, graph);
        return res;
    }
    private:
    vector<vector<int>> res;
    void dfs(int u, int n, vector<int>& currPath, vector<vector<int>>& graph)
    {
        if (u == n-1) {
            res.push_back(currPath);
            return;
        }

        for (int neighbor : graph[u]) {
            currPath.push_back(neighbor);
            dfs(neighbor, n, currPath, graph);
            currPath.pop_back(); // backtrack
        }
    }
};