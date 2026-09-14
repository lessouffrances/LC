class Solution
{
    public:
    // rule: the num on the idx is the parent of the idx
    // parent: [1,-1,1,2,5,2]
    // child:  [0,1,2,3,4,5]
    // true

    // parent: [1,-1,3,4,5,2]
    // child:  [0,1,2,3,4,5]
    // false
    bool isArrayValidTree(vector<int>& nums)
    {
        buildGraph(nums);

        queue<int> q;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == -1) q.push(i); // seed root
        }

        int nodesVisited = 0;
        unordered_set<int> visited;
        while (!q.empty()) {
            auto currNode = q.front();
            q.pop();

            // cycle detected
            if (visited.count(currNode)) return false;
            visited.insert(currNode);
            nodesVisited++;

            for (auto& neighbor : graph[currNode]) {
                q.push(neighbor);
            }
        }
        return nodesVisited == nums.size();
    }

    private:
    // as long as no cycle, is a tree
    unordered_map<int, vector<int>> graph;
    vector<int> indegree;
    void buildGraph(vector<int>& nums)
    {
        int n = nums.size();
        indegree.resize(n);

        for (int i=0; i<n; i++) {
            int u = nums[i];
            int v = i;
            graph[u].push_back(v);
            indegree[v]++;
        }
    }
};
