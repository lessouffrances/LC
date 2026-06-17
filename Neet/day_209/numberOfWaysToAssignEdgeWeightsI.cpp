class Solution 
{
    public:
    int assignEdgeWeights(vector<vector<int>>& edges) 
    {
        if (edges.empty()) return 0;
        const long long MOD = 1e9+7;
        buildAdjLists(edges);

        int maxDepth = dfs(1);
        // then need to compute 2^(maxDepth-1) % MOD
        return fastPow(2, maxDepth-1, MOD);
    }
    private:
    unordered_map<int, vector<int>> adjList;
    unordered_set<int> visited;

    int dfs(int u)
    {
        int maxDepth = 0;
        visited.insert(u);

        for (auto& neighbor : adjList[u]) {
            if (visited.count(neighbor)) continue;
            maxDepth = max(maxDepth, 1+dfs(neighbor));
        }
        return maxDepth;
    }

    void buildAdjLists(vector<vector<int>>& edges)
    {
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u); // undirected 
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