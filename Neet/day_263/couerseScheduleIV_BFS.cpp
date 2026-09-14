class Solution 
{
    public:

    // find the topo order then the queries can be made
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, 
        vector<vector<int>>& queries) 
    {
        buildGraph(numCourses, prerequisites);

        // seed all courses with indegree = 0
        queue<int> q;
        for (int course=0; course<numCourses; course++) {
            if (indegree[course] == 0) q.push(course);
        }

         // construct this map while BFS
        unordered_map<int, unordered_set<int>> prepLookup; 
        int courseVisited = 0;
        while (!q.empty()) {
            auto currCourse = q.front();
            q.pop();
            courseVisited++;

            for (auto& nextCourse : graph[currCourse]) {
                indegree[nextCourse]--;
                // now the currCourse is the prep for the nextCourse
                // and all the prep for the currCourse is the prep for the nextCourse too
                prepLookup[nextCourse].insert(currCourse);
                for (auto& prep : prepLookup[currCourse]) {
                    prepLookup[nextCourse].insert(prep);
                }
                if (indegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }

        // there is this possibility that the topo order does not even exist!
        if (courseVisited != numCourses) return {};
        vector<bool> res;
        for (auto& q : queries) {
            int u = q[0];
            int v = q[1];
            res.push_back(prepLookup[v].count(u));
        }
        return res;
    }

    private:
    unordered_map<int, vector<int>> graph;
    vector<int> indegree;
    void buildGraph(int numCourses, vector<vector<int>>& prerequisites)
    {
        // allocate space for this array
        indegree.resize(numCourses);

        for (auto& prep : prerequisites) {
            int u = prep[0];
            int v = prep[1];
            graph[u].push_back(v);
            indegree[v]++;
        }
    }
};