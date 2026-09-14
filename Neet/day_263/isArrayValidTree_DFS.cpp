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

        if (dfsHasCycle(-1)) return false;
        for (int i=0; i<nums.size(); i++) {
            if (!visited.count(i)) return false;
        }
        return true;
    }

    private:
    // as long as no cycle, is a tree
    unordered_set<int> visited;
    unordered_map<int, vector<int>> graph;

    bool dfsHasCycle(int u)
    {
        visited.insert(u);

        for (auto& v : graph[u]) {
            if (visited.count(v)) return true;
            dfsHasCycle(v);
        }
        return false;
    }  
    
    void buildGraph(vector<int>& nums)
    {
        for (int i=0; i<nums.size(); i++) {
            int u = nums[i];
            int v = i;
            graph[u].push_back(v);
        }
    }
};
