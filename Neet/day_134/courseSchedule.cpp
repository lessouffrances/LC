class Solution 
{
    public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        if (prerequisites.empty()) return true;   

        buildGraph(numCourses, prerequisites);

        // FULL DFS 
        for (int i=0; i<numCourses; i++) {
            if (visited.count(i)) continue;
            ancestorStack.clear();
            if (dfsDetectCycle(i)) return false;
        }
        return true;
    }
    private:
    unordered_set<int> ancestorStack;
    unordered_set<int> visited;
    unordered_map<int, vector<int>> graph;
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
        return false;
    }
    void buildGraph(int numCourses, vector<vector<int>>& prerequisites)
    {
        for (int i=0; i<numCourses; i++) {
            graph[i];
        }
        for (auto& prep : prerequisites) {
            int u = prep[1];
            int v = prep[0];
            graph[u].push_back(v);
        }
    }
};