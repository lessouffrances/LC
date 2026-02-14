class Solution 
{
    public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        if (prerequisites.empty()) {
            vector<int>res(numCourses);
            iota(res.begin(), res.end(), 0);
            return res;
        }

        buildGraph(numCourses, prerequisites);
        for (int course=0; course<numCourses; course++) {
            if (visited.count(course)) continue;
            visited.insert(course);
            if (dfsDetectCycle(course, numCourses, graph)) return {};
        }
        reverse(finishingOrder.begin(), finishingOrder.end());
        return finishingOrder;
    }
    private:
    unordered_map<int, vector<int>> graph;
    vector<int> finishingOrder;
    unordered_set<int> ancestorStack;
    unordered_set<int> visited;
    bool dfsDetectCycle(int u, int numCourses, unordered_map<int, vector<int>>& graph)
    {
        ancestorStack.insert(u);

        for (auto& v : graph[u]) {
            if (ancestorStack.count(v)) return true;
            if (visited.count(v)) continue;
            visited.insert(v);
            if (dfsDetectCycle(v, numCourses, graph)) return true;
        }
        ancestorStack.erase(u);
        finishingOrder.push_back(u);
        return false;
    }
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
};