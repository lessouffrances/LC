



class Solution 
{
    public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        // There is no prep, can take course in anytime
        if (prerequisites.empty()) return true;
        buildGraph(numCourses, prerequisites);

        // do FULL-dfs on the graph
        for (int i=0; i<numCourses; i++) {
            if (!visited.count(i)) {
                if (dfs(i)) return false;
            }
        }
        return true;
    }

    private:
    unordered_map<int, vector<int>> graph; // adjList
    unordered_set<int> visited;
    unordered_set<int> ancestorStack;
    // dfs to detect if cycle exists

    // 1->2->3->4->5
    //          |
    //          6->7
    bool dfs(int u)
    {
        ancestorStack.insert(u);
        visited.insert(u);

        for (int v : graph[u]) {
            if (ancestorStack.count(v)) return true;

            if (visited.count(v)) continue;
            if (dfs(v)) return true;
        }
        ancestorStack.erase(u);
        return false;
    }

    void buildGraph(int numCourses, vector<vector<int>>& prerequisites)
    {
        if (prerequisites.empty()) return;

        for (int i=0; i<numCourses; i++) {
            graph[i]; // nodes can be isolated
        }
        for (auto& prep : prerequisites) {
            int u = prep[1];
            int v = prep[0];
            graph[u].push_back(v);
        }
    }
};