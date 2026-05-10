// T: O(V + E)
// S: O(V + E)

class Solution 
{
    public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        if (prerequisites.empty()) return true;

        buildGraph(numCourses, prerequisites);

        // do FULL-dfs on the graph
        for (int course=0; course<numCourses; course++) {
            if (visited.count(course)) continue;
            if (dfsHasCycle(course)) return false;
        }
        return true;
    }

    private:
    unordered_map<int, vector<int>> graph; // int acts as the pre for adjList
    unordered_set<int> visited;
    unordered_set<int> ancestorStack;

    bool dfsHasCycle(int u) {
        visited.insert(u);
        ancestorStack.insert(u);

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
        // this situation does exist
        for (int course=0; course<numCourses; course++) {
            graph[course] = {};
        }

        for (auto& prep : prerequisites) {
            int v = prep[0];
            int u = prep[1];
            graph[u].push_back(v);
        }
    }
};
