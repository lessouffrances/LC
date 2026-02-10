class Solution 
{
    public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        if (equations.empty() || values.empty() || queries.empty()) return {};

        buildGraph(equations, values);

        int n = queries.size();
        vector<double> res;

        for (int i=0; i<n; i++) {
            string u = queries[i][0];
            string v = queries[i][1];

            res.push_back(bfs(u, v, graph));
        }
        return res;
    }
    private:
    unordered_map<string, vector<pair<string, double>>> graph;
    double bfs(const string& u, const string& v, unordered_map<string, vector<pair<string, double>>>& graph)
    {
        if (!graph.count(u) || !graph.count(v)) return -1.0;
        if (u == v) return 1.0;

        queue<pair<string, double>> q;
        set<string> visited;
        q.push( {u, 1.0} );
        visited.insert(u);

        while (!q.empty()) {
            auto [node, currProduct] = q.front();
            q.pop();
        
            if (node == v) return currProduct;

            for (auto& [v, weight] : graph[node]) {
                if (visited.count(v)) continue;
                visited.insert(v);
                q.push( {v, currProduct * weight} );
            }
        }
        return -1.0;
    }

    void buildGraph(vector<vector<string>>& equations, vector<double>& values)
    {
        int n = equations.size();
        for (int i=0; i<n; i++) {
            string u = equations[i][0];
            string v = equations[i][1];

            graph[u].push_back( {v, values[i]} );
            graph[v].push_back( {u, 1/values[i] });
        }
    }
};