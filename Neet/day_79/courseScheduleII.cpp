class Solution
{
    public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        // if no prerequisites, can take courses in any order
        if (prerequisites.empty()) {
            vector<int> order;
            for (int course=0; course<numCourses; course++) {
                order.push_back(course);
            }
            return order;
        }

        constructGraph(numCourses, prerequisites);
        for (int source=0; source<numCourses; source++) {
            if (visited.find(source) != visited.end()) continue;
            visited.insert(source);
            // if has cycle, no valid topological order
            if (dfsFinishingOrderAncestorStack(source, graph)) return {};
        }

        reverse(finishingOrder.begin(), finishingOrder.end());
        return finishingOrder;
    }

    private:
    unordered_map<int, vector<int>> graph;
    vector<int> finishingOrder;
    set<int> ancestorStack;
    set<int> visited;
    bool dfsFinishingOrderAncestorStack(int u, unordered_map<int, vector<int>>& graph)
    {
        ancestorStack.insert(u);

        if (graph.count(u)) {
            for (const auto& v : graph[u]) {
                if (ancestorStack.find(v) != ancestorStack.end()) return true;
                if (visited.find(v) != visited.end()) continue;

                visited.insert(v);
                if (dfsFinishingOrderAncestorStack(v, graph)) return true;
            }
        }
        ancestorStack.erase(u);
        finishingOrder.push_back(u);
        return false;
    }

    void constructGraph(int numCourses, vector<vector<int>>& prerequisites)
    {
        if (prerequisites.empty()) return;
        for (int i=0; i<numCourses; i++) {
            graph[i] = {};
        }

        for (auto& pre : prerequisites) {
            int v = pre[0];
            int u = pre[1];
            graph[u].push_back(v);
        }
    }
};
