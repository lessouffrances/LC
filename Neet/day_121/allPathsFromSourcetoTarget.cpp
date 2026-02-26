



class Solution 
{
    public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        if (graph.empty()) return {};

        int n = graph.size();
        vector<int> startPath;
        startPath.push_back(0);
        dfs(0, startPath, n-1, graph);
        return res;
    }
    private:
    vector<vector<int>> res;
    void dfs(int u, vector<int>& currPath, int target, vector<vector<int>>& graph)
    {
        // reach the last node
        if (u == target) {
            res.push_back(currPath);
            return;
        }

        for (auto& neighbor : graph[u]) {
            currPath.push_back(neighbor);
            dfs(neighbor, currPath, target, graph);

            currPath.pop_back(); // backtrack
        }
    }
};