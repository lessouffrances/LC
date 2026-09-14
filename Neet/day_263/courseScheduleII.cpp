class Solution 
{
    public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        buildGraph(numCourses, prerequisites);

        // seed all courses with no prep
        queue<int> q;
        for (int course=0; course<numCourses; course++) {
            if (indegree[course] == 0) {
                q.push(course);
            }
        }

        int courseTaken = 0;
        vector<int> order;
        while (!q.empty()) {
            auto currCourse = q.front();
            q.pop();
            courseTaken++;
            order.push_back(currCourse);

            for (auto& nextCourse : graph[currCourse]) {
                indegree[nextCourse]--; // because currCourse has already been taken
                if (indegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }
        if (courseTaken == numCourses) return order;
        return {};
    }

    private:
    unordered_map<int, vector<int>> graph;
    vector<int> indegree;
    void buildGraph(int numCourses, vector<vector<int>>& prerequisites)
    {
        indegree.resize(numCourses);

        for (auto& prep : prerequisites) {
            int u = prep[1];
            int v = prep[0];
            graph[u].push_back(v);
            // u -> v
            indegree[v]++;
        }
    }
};