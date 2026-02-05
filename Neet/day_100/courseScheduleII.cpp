

class Solution 
{
    public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        buildGraph(numCourses, prerequisites);
        for (int course=0; course<numCourses; course++) {
            if (visited.count(course)) continue;
            visited.insert(course);
            if (dfs(course, numCourses, graph)) return {};
        }

        reverse(finishingOrder.begin(), finishingOrder.end());
        return finishingOrder;
    }

    private:
    unordered_map<int, vector<int>> graph;
    unordered_set<int> visited;
    vector<int> finishingOrder;
    unordered_set<int> ancestorStack;
    bool dfs(int u, int n, unordered_map<int, vector<int>>& graph) 
    {
        ancestorStack.insert(u);

        for (int v : graph[u]) {
            if (ancestorStack.count(v)) return true;
            if (visited.count(v)) continue;
            visited.insert(v);
            if (dfs(v, n, graph)) return true;
        }

        ancestorStack.erase(u);
        finishingOrder.push_back(u);
        return false;
    }

    void buildGraph(int numCourses, vector<vector<int>>& prerequisites) 
    {
        for (int i=0; i<numCourses; i++) {
            graph[i] = {};
        }

        for (auto prep : prerequisites) {
            int u = prep[1];
            int v = prep[0];

            graph[u].push_back(v);
        }
    }
};