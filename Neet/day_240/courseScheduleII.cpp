class Solution 
{
    public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        if (numCourses == 0) return {};
        if (prerequisites.empty()) {
            vector<int> res;
            for (int course=0; course<numCourses; course++) {
                res.push_back(course);
            }
            return res;
        }
        
        buildGraph(numCourses, prerequisites);

        for (int course=0; course<numCourses; course++) {
            if (visited.count(course)) continue;
            if (dfsHasCycle(course)) return {};
        }
        reverse(finishingOrder.begin(), finishingOrder.end());
        return finishingOrder;
    }

    private:
    unordered_map<int, vector<int>> graph; // adjList
    unordered_set<int> visited;
    unordered_set<int> ancestorStack;
    vector<int> finishingOrder;
    
    bool dfsHasCycle(int u)
    {
        ancestorStack.insert(u);
        visited.insert(u);

        for (auto& v : graph[u]) {
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
        for (int course=0; course<numCourses; course++) {
            graph[course] = {};
        }

        for (auto& prep : prerequisites) {
            int v = prep[0];
            int u = prep[1];
            graph[u].push_back(v); // single edge
        }
    }
};