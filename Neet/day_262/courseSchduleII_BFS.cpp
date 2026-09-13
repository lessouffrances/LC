class Solution 
{
    public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        buildGraph(numCourses, prerequisites);

        // seed all courses with 0 indegree
        queue<int> q;
        for (int course=0; course<numCourses; course++) {
            if (indegree[course] == 0) q.push(course);
        }

        vector<int> topoOrder;
        while (!q.empty()) {
            auto currCourse = q.front();
            q.pop();
            topoOrder.push_back(currCourse);

            for (auto& nextCourse : graph[currCourse]) {
                indegree[nextCourse]--;
                if (indegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }

        if (topoOrder.size() == numCourses) return topoOrder;
        return {};
    }

    private:
    vector<int> indegree;
    unordered_map<int, vector<int>> graph;

    void buildGraph(int numCourses, vector<vector<int>>& prerequisites)
    {
        indegree.resize(numCourses);
        
        for (auto& prep : prerequisites) {
            int u = prep[1];
            int v = prep[0];
            graph[u].push_back(v);
            indegree[v]++;
        }
    }
};