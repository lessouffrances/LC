class Solution 
{
    public:
    vector<bool> checkIfPrerequisite(int numCourses, 
        vector<vector<int>>& prerequisites, vector<vector<int>>& queries) 
    {
        buildGraph(numCourses, prerequisites);
        // seed all indegree == 0
        queue<int> q;
        for (int course=0; course<numCourses; course++) {
            if (indegree[course] == 0) {
                q.push(course);
            }
        }
        // unordered_map<int, unordered_set<int>> prepLookup;
        vector<vector<bool>> prepLookupMatrix(numCourses, vector<bool>(numCourses, false));

        // build topo order and fill in the lookup table
        while (!q.empty()) {
            auto currCourse = q.front();
            q.pop();
            for (auto& nextCourse : graph[currCourse]) {
                indegree[nextCourse]--;
                // relation built
                // currCourse -> nextCourse
                prepLookupMatrix[currCourse][nextCourse] = true;
                for (int course=0; course<numCourses; course++) {
                    if (prepLookupMatrix[course][currCourse]) {
                        prerequisites[course][nextCourse] = true;
                    }
                }
                if (indegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }

        // process queries
        vector<bool> res;
        for (auto& q : queries) {
            int u = q[0];
            int v = q[1];
            res.push_back(prepLookupMatrix[u][v]);
        }

        return res;
    }

    private:
    unordered_map<int, vector<int>> graph;
    vector<int> indegree;
    void buildGraph(int numCourses, vector<vector<int>>& prerequisites)
    {
        indegree.resize(numCourses);

        for (auto& prep : prerequisites) {
            int u = prep[0];
            int v = prep[1];
            graph[u].push_back(v);
            indegree[v]++;
        }
    }
};