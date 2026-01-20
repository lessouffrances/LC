class Solution
{
    public: 
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        if (prerequisites.empty()) return true;
        buildGraph(numCourses, prerequisites);

        for (int course=0; course<numCourses; course++) {
            if (visited.count(course)) continue;
            if (dfs(course, graph)) return false;
        }
        return true;
    }

    private:
    unordered_map<int, vector<int>> graph;
    unordered_set<int> ancestorStack;
    unordered_set<int> visited;
    bool dfs(int u, unordered_map<int, vector<int>>& graph)
    {
        ancestorStack.insert(u);
        visited.insert(u);

        if (graph.count(u)) {
            for (auto& v : graph[u]) {
                if (ancestorStack.count(v)) return true;
                if (visited.count(v)) continue;
                if (dfs(v, graph)) return true;
            }
        }

        ancestorStack.erase(u);
        return false;
    }

    void buildGraph(int numCourses, vector<vector<int>>& prerequisites)
    {
        for (int course=0; course<numCourses; course++) {
            graph[course] = {};
        }

        for (auto& pre : prerequisites) {
            int u = pre[1];
            int v = pre[0];

            graph[u].push_back(v);
        }
    }
};