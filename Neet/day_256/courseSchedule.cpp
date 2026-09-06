class Solution 
{
    public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        if (numCourses == 0 || numCourses == 1) return true;
        buildGraph(numCourses, prerequisites);

        for (int course=0; course<numCourses; course++) {
            if (visited.count(course)) continue;
            if (dfsHasCycle(course)) return false;
        }
        return true;
    }

    private:
    unordered_set<int> visited;
    unordered_set<int> ancestorStack;
    unordered_map<int, vector<int>> graph;

    void buildGraph(int numCourses, vector<vector<int>>& prerequisites)
    {
        for (int course=0; course<numCourses; course++) {
            graph[course] = {};
        }
        for (auto& prep : prerequisites) {
            int v = prep[0];
            int u = prep[1];
            graph[u].push_back(v);
        }
    }

    bool dfsHasCycle(int u)
    {
        visited.insert(u);
        ancestorStack.insert(u);
        if (graph.count(u)) {
            for (auto& v : graph[u]) {
                if (ancestorStack.count(v)) return true;
                if (visited.count(v)) continue;
                if (dfsHasCycle(v)) return true;
            }
        }
        ancestorStack.erase(u);
        return false;
    }
};