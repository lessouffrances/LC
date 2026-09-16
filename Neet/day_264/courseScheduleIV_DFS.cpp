class Solution 
{
    public:
    vector<bool> checkIfPrerequisite(int numCourses, 
        vector<vector<int>>& prerequisites, vector<vector<int>>& queries) 
    {
        buildGraph(numCourses, prerequisites);

        vector<bool> res;
        for (auto& q : queries) {
            int u = q[0], v = q[1];
            res.push_back(dfsIsPrep(u, v));
        }
        return res;
    }

    private:
    bool dfsIsPrep(int before, int after)
    {
        for (auto& v : graph[before]) {
            if (v == after) return true;
            if (dfsIsPrep(v, after)) return true;
        }
        return false;
    }

    unordered_map<int, vector<int>> graph;
    void buildGraph(int numCourses, vector<vector<int>>& prerequisites)
    {
        for (auto& prep : prerequisites) {
            int u = prep[0];
            int v = prep[1];
            graph[u].push_back(v);
        }
    }
};