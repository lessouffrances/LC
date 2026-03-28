

// Time: O(V), because each node is visited once only.
// Space: O(V+E), because we build the graph with E
class Solution 
{
    public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        // explain it in business logic:
        // when there is no course at all and when there is no restriction on prerequisites
        // we can finish all courses
        if (numCourses == 0 || prerequisites.empty()) return true;

        buildGraph(numCourses, prerequisites);

        // FULL-DFS
        for (int course=0; course<numCourses; course++) {
            if (visited.count(course)) continue;
            ancestorStack.clear();
            if (dfsDetectCycle(course)) return false;
        }
        return true;
    }

    private:
    unordered_map<int, vector<int>> graph;
    unordered_set<int> ancestorStack;
    unordered_set<int> visited;
    bool dfsDetectCycle(int u)
    {
        visited.insert(u);
        ancestorStack.insert(u);

        for (int v : graph[u]) {
            if (ancestorStack.count(v)) return true;
            if (visited.count(v)) continue;
            if (dfsDetectCycle(v)) return true;
        }

        ancestorStack.erase(u);
        return false;
    }

    void buildGraph(int numCourses, vector<vector<int>>& prerequisites)
    {
        // some course/nodes can be isolated
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