


// Time: O(V + E)
// Space: O(V + E)
class Solution 
{
    public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        if (numCourses == 0) return {};
        buildGraph(numCourses, prerequisites);
        // Do FULL-DFS:
        for (int i=0; i<numCourses; i++) {
            if (visited.count(i)) continue;
            if (dfsDetectCycle(i)) return {};
        }
        reverse(finishingOrder.begin(), finishingOrder.end());
        return finishingOrder;

    }
    private:
    unordered_map<int, vector<int>> graph; //adjList
    unordered_set<int> visited;
    unordered_set<int> ancestorStack;
    vector<int> finishingOrder;
    bool dfsDetectCycle(int u)
    {
        ancestorStack.insert(u);
        visited.insert(u);

        for (int v : graph[u]) {
            if (ancestorStack.count(v)) return true;
            if (visited.count(v)) continue;
            if (dfsDetectCycle(v)) return true;
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
            int u = prep[1];
            int v = prep[0];
            graph[u].push_back(v);
        }
    }
};