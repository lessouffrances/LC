class Solution 
{
    public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        if (equations.empty() || values.empty()) return {};
        buildGraph(equations, values);

        vector<double> res;
        int n = queries.size();
        for (int i=0; i<n; i++) {
            string src = queries[i][0];
            string dest = queries[i][1];
            res.push_back(bfs(src, dest, graph));
        }
        return res;
    }
    private:
    unordered_map<string, vector<pair<string, double>>> graph;
    double bfs(const string& source, const string& destination, 
        unordered_map<string, vector<pair<string, double>>>& graph)
    {
        if (!graph.count(source)) return -1.0;
        if (source == destination) return 1.0;
        
        queue<pair<string, double>> q;
        q.push( {source, 1.0} );
        set<string> visited;
        visited.insert(source);

        // double product = 1.0;
        while (!q.empty()) {
            auto [u, product] = q.front();
            q.pop();

            if (u == destination) return product;

            for (auto [v, weight] : graph[u]) {
                if (!visited.count(v)) {
                    q.push( {v, (double)product * weight} );
                    visited.insert(v);
                }
            }
        }

        return -1.0;

    }
    void buildGraph(vector<vector<string>>& equations, vector<double>& values)
    {
        if (equations.empty() || values.empty()) return;
        int n = equations.size();

        for (int i=0; i<n; i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double weight = values[i];

            graph[u].push_back( {v, weight} );
            graph[v].push_back( {u, (double)1 / weight} );
        }
    }
};