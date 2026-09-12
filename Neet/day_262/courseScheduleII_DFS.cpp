class Solution 
{
    public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        buildGraph(numCourses, prerequisites);

        // full-DFS
        for (int i=0; i<numCourses; i++) {
            if (visited.count(i)) continue;
            if (dfsHasCycle(i)) return {}; // has cycle
        }
        // reverse of the finishing order is the topo order
        reverse(finishingOrder.begin(), finishingOrder.end());
        return finishingOrder;
    }

    private:
    unordered_map<int, vector<int>> graph;
    vector<int> finishingOrder;
    unordered_set<int> visited;
    unordered_set<int> ancestorStack;

    bool dfsHasCycle(int u)
    {
        visited.insert(u);
        ancestorStack.insert(u);

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
        for (int i=0; i<numCourses; i++) graph[i] = {};
        for (auto& prep : prerequisites) {
            int u = prep[1];
            int v = prep[0];
            graph[u].push_back(v); 
        }
    }
};