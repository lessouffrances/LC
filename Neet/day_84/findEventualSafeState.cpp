class Solution 
{
    public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<int> state(n, 0);
        // 2 -> safe
        // 1 -> visited, unsafe
        // 0 -> unvisited

        vector<int> res;
        for (int node=0; node<n; node++) {
            if (isSafe(node, graph, state)) {
                res.push_back(node);
            }
        }

        sort(res.begin(), res.end());
        return res;
    }
    private:
    bool isSafe(int node, vector<vector<int>>& graph, vector<int>& state)
    {
        // if visited, there is only 2 options: 1 and 2
        if (state[node] != 0) {
            return state[node] == 2;
        }

        // if visited
        state[node] = 1;
        
        for (int neighbor : graph[node]) {
            if (state[neighbor] == 1) return false;
            if (!isSafe(neighbor, graph, state)) return false;
        }

        state[node] = 2;
        return true;
    }
};