class Solution 
{
    public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        if (graph.empty()) return {};
        int n = graph.size();

        vector<int> res;
        vector<int> state(n, 0);
        for (int i=0; i<n; i++) {
            if (isSafe(i, graph, state)) {
                res.push_back(i);
            }
        }
        return res;
    }
    private:
    // 0 -> unvisited;
    // 1 -> visited, unsafe
    // 2 -> visited, safe
    bool isSafe(int node, vector<vector<int>>& graph, vector<int>& state) 
    {
        if (state[node] != 0) {
            return state[node] == 2;
        }

        state[node] = 1;

        for (auto& neighbor : graph[node]) {
            if (state[neighbor] == 1) return false;
            if (!isSafe(neighbor, graph, state)) return false;
        }
        
        state[node] = 2;
        return true;
    }
};