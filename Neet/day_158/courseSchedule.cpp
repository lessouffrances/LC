class Solution 
{
    public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        if (numCourses == 0 || prerequisites.empty()) return true;

        buildGraph(numCourses, prerequisites);

        // full DFS
        for (int course=0 course<numCourses; course++) {
            if (visited.count(course)) continue;
            if (dfsHasCycle(course)) return false;
        }
        return true;
    }

    private:
    unordered_map<int, vector<int>> graph;
    unordered_set<int> ancestorStack;
    unordered_set<int> visited;

    bool dfsHasCycle(int u)
    {
        ancestorStack.insert(u);
        visited.insert(u);

        for (int v : graph[u]) {
            if (ancestorStack.count(v)) return true;
            if (visited.count(v)) continue;
            if (dfsHasCycle(v)) return true;
        }

        ancestorStack.erase(u);
        return false;
    }

    void buildGraph(int numCourses, vector<vector<int>>& prerequisites)
    {
        for (int course=0; course<numCourses; course++) {
            graph[course] = {};
        }

        for (auto& prep : prerequisites) {
            int u = prep[1];
            int v = prep[0];
            graph[u].push_back(v);
        }
    }
};