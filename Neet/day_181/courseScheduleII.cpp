class Solution 
{
    public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        if (prerequisites.empty()) {
            vector<int> res;
            for (int i = 0; i < numCourses; i++) res.push_back(i);
            return res;
        }
        buildGraph(numCourses, prerequisites);

        // full DFS
        for (int course=0; course<numCourses; course++) {
            if (visited.count(course)) continue;
            if (dfsHasCycle(course)) return {};
        }
        reverse(finishOrder.begin(), finishOrder.end());
        return finishOrder;
    }

    private:
    unordered_map<int, vector<int>> graph; // adjList
    unordered_set<int> ancestorStack;
    unordered_set<int> visited;
    vector<int> finishOrder;

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
        finishOrder.push_back(u);
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