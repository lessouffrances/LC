class Solution 
{
    public:
    int assignEdgeWeights(vector<vector<int>>& edges) 
    {
        if (edges.empty()) return 1;
        buildTreeAdjList(edges);
        int maxDepth = dfs(1, 0);
        return fastPow(2, maxDepth-1, 1e9+7);
    }

    private:
    unordered_map<int, vector<int>> tree;

    int dfs(int currNode, int parentNode)
    {
        int maxDepth = 0;
        for (auto& neighbor : tree[currNode]) {
            if (neighbor == parentNode) continue;
            maxDepth = max(maxDepth, dfs(neighbor, currNode)+1);
        }
        return maxDepth;
    }

    void buildTreeAdjList(vector<vector<int>>& edges)
    {
        for (auto& edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
    }

    long long fastPow(long long base, long long exp, long long mod)
    {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) result = result * base % mod;
            base = base * base % mod;
            exp /= 2;
        }
        return result;
    }

    
};