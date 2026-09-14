class Solution 
{
    public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, 
        vector<vector<int>>& queries) 
    {
        buildGraph(numCourses, prerequisites);
        vector<bool> res;
        for (auto& q : queries) {
            int u = q[0];
            int v = q[1];
            res.push_back(dfs(u, v));
        }
        return res;
    }

    private:
    unordered_map<int, vector<int>> graph;

    // if prep -> after exists, return true
    // given that the topo order exists, we know there is no cycle
    bool dfs(int prep, int after) 
    {
        for (auto& next : graph[prep]) {
            if (next == after) return true;
            if (dfs(next, after)) return true;;
        }
        return false;
    }

    void buildGraph(int numCourses, vector<vector<int>>& prerequisites)
    {
        for (auto& prep : prerequisites) {
            int u = prep[0];
            int v = prep[1];
            graph[u].push_back(v);
        }
    }
};