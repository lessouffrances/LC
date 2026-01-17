class Solution 
{
    public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        // 0 -> unvisited
        // 1 -> visited but unsafe
        // 2 -> safe
        int n = graph.size();
        vector<int> state(n, 0);
        vector<int> res;

        for (int node=0; node<n; node++) {
            if (isSafe(node, graph, state)) {
                res.push_back(node);
            }
        }
        return res;
    }
    private:
    bool isSafe(int node, vector<vector<int>>& graph, vector<int>& state)
    {
        // check if this node has been processed
        if (state[node] != 0) {
            return state[node] == 2;
        }

        state[node] = 1; // mark as visited

        // if the neighbors are not safe, this node is not safe
        for (int neighbor : graph[node]) {
            if (state[neighbor] == 1) return false;
            if (!isSafe(neighbor, graph, state)) {
                return false;
            }
        }
        state[node] = 2;
        return true;
    }
};