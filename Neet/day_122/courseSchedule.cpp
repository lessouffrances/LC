class Solution 
{
    public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        buildGraph(numCourses, prerequisites);
        // FULL-DFS: if theres any topological order exists in this graph
        for (int i=0; i<numCourses; i++) {
            if (visited.count(i)) continue;
            if (dfsDetectCycle(i, graph)) return false;
        }
        return true;
    }
    private:
    unordered_map<int, vector<int>> graph; //adjList
    unordered_set<int> visited;
    unordered_set<int> ancestorStack;
    vector<int> finishingOrder;
    bool dfsDetectCycle(int u, unordered_map<int, vector<int>>& graph)
    {
        ancestorStack.insert(u);
        visited.insert(u);

        for (int v : graph[u]) {
            if (ancestorStack.count(v)) return true; // back-edge: cycle!
            if (visited.count(v)) continue; 
            if (dfsDetectCycle(v, graph)) return true;
        }
        // u is fully explored at this moment
        ancestorStack.erase(u);
        // u finishes after all its descendants 
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