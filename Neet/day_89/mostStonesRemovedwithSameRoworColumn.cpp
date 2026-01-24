class Solution 
{
    public:
    int removeStones(vector<vector<int>>& stones) 
    {
        if (stones.empty()) return 0;

        buildGraph(stones);
        int n = stones.size();

        int numOfConnectedComp = 0;
        for (int i=0; i<n; i++) {
            if (visited.count(i)) continue;
            dfs(i, graph);
            numOfConnectedComp++;
        }

        return n-numOfConnectedComp;
    }
    private:
    unordered_map<int, vector<int>> graph;
    unordered_set<int> visited;
    void dfs(int u, unordered_map<int, vector<int>>& graph) 
    {
        visited.insert(u);

        if (graph.count(u)) {
            for (auto& stone : graph[u]) {
                if (visited.count(stone)) continue;
                dfs(stone, graph);
            }
        }
    }
    void buildGraph(vector<vector<int>>& stones)
    {
        if (stones.empty()) return;
        int n = stones.size();

        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                if (stones[i][0] == stones[j][0] 
                    || stones[i][1] == stones[j][1]) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
    }
};