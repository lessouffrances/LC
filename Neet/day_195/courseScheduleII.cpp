class Solution 
{
    public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        if (prerequisites.empty()) {
            vector<int> res;
            for (int course=0; course<numCourses; course++) {
                res.push_back(course);
            }
            return res;
        }
        buildGraph(numCourses, prerequisites);

        // FULL-dfs on this graph
        // the finishing order and visietd set are global
        for (int course=0; course<numCourses; course++) {
            if (visited.count(course)) continue;
            if (dfsHasCycle(course)) return {};
        }
        reverse(finishingOrder.begin(), finishingOrder.end());
        return finishingOrder;
    }

    private:
    unordered_map<int, vector<int>> graph; // adjList
    unordered_set<int> ancestorStack;
    unordered_set<int> visited;
    vector<int> finishingOrder;

    // true => has cycle
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
        finishingOrder.push_back(u);
        return false;
    }

    void buildGraph(int numCourses, vector<vector<int>>& prerequisites)
    {
        // all the courses that have a course as their pre
        for (int course=0; course<numCourses; course++) {
            graph[course] = {};
        }

        // u -> v relationship
        for (auto& prep : prerequisites) {
            int u = prep[1];
            int v = prep[0];
            graph[u].push_back(v);
        }
    }
};