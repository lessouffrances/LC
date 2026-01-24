class Solution 
{
    public:
    int removeStones(vector<vector<int>>& stones) 
    {
        if (stones.empty()) return 0;
        int n = stones.size();

        buildGraph(stones);
        int connectedComp = 0;
        for (int i=0; i<n; i++) {
            if (visited.count(i)) continue;
            dfs(i, graph);
            connectedComp++;
        }

        return n - connectedComp;
    }
    private:
    unordered_map<int, vector<int>> graph;
    unordered_set<int> visited;
    void dfs(int stoneIdx, unordered_map<int, vector<int>>& graph) 
    {
        visited.insert(stoneIdx);

        for (auto& stone : graph[stoneIdx]) {
            if (visited.count(stone)) continue;
            dfs(stone, graph);
        }
    }

    void buildGraph(vector<vector<int>>& stones) {
        if (stones.empty()) return;
        int n = stones.size();
        
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    graph[i].push_back(j); // idx of stones
                    graph[j].push_back(i);
                }
            }
        }
    } 
};