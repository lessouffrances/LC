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

        // check connectivity 
        for (int i=0; i<nums.size(); i++) {
            if (visited.count(i)) return false; // some nodes are not connected
        }
        return true;
    }

    private:
    // as long as no cycle, is a tree
    unordered_set<int> ancestorStack;
    unordered_set<int> visited;
    bool dfsHasCycle(int u) 
    {
        visited.insert(u);
        ancestorStack.insert(u);

        for (auto& v : graph[u]) {
            if (ancestorStack.count(v)) return true;
            if (visited.count(v)) continue;
            if (dfsHasCycle(v)) return true;
        }
        ancestorStack.erase(u);
        return false;
    }
    // use the rule to build graph
    unordered_map<int, vector<int>> graph;
    void buildGraph(vector<int>& nums)
    {
        for (int i=0; i<nums.size(); i++) {
            int u = nums[i];
            int v = i;
            graph[u].push_back(v);
        }
    }
};
